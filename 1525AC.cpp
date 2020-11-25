#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

constexpr inline int fzl(int st){
	for(int i=9;i>0;i--){
		if(st%10==0) return i;
		st/=10;
	}
	return 0;
}

template<typename T>
static constexpr inline T pown(T x, unsigned p) {
    T r = 1;
	while (p) {
        if (p & 0x1) r *= x;
        x *= x;
        p >>= 1;
    }
    return r;
}

constexpr inline int swapd(int st, int zloc, int curloc){
	int s1=st/pown(10, 9-zloc)%10, s2=st/pown(10, 9-curloc)%10;
	st=st-s1*pown(10, 9-zloc)-s2*pown(10, 9-curloc);
	st=st+s1*pown(10, 9-curloc)+s2*pown(10, 9-zloc);
	return st;
}

int main()
{
	int st=0, d[9]={24, 135, 26, 157, 2468, 359, 48, 579, 68};
	map<int, int> sts;
	queue<pair<int, int>> q;
	for(int i=0;i<9;i++){
		int t;
		cin>>t;
		st=st*10+t;
	}
	q.push({st, 0});
	while(!q.empty()){
		int mv=q.front().second, zloc, addto;
		st=q.front().first;
		q.pop();
		if(st==123456780){
			cout<<mv;
			return 0;
		}
		if(mv>31){
			cout<<-1;
			return 0;
		}
		if(sts.find(st)==sts.end() || sts[st]>mv) sts[st]=mv;
		else continue;
		zloc=fzl(st);
		addto=d[zloc-1];
		while(addto>0){
			int curloc=addto%10, newst;
			addto/=10;
			newst=swapd(st, zloc, curloc);
			if(sts.find(newst)==sts.end() || sts[newst]>mv+1)
				q.push({newst, mv+1});
		}
	}
	cout<<-1;
}