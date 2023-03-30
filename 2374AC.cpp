#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

lld cal(vi& a, int s, int e, int val);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, mx=0;
	cin>>n;
	vi a(n, 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(mx<a[i]) mx=a[i];
	}
	cout<<cal(a, 0, n, mx);
	return 0;
}

lld cal(vi& a, int s, int e, int val){
	int idx=-1, mx=0;
	lld rs, re;
	if(s>=e) return 0;
	if(s+1==e){
		if(a[s]!=val) return val-a[s];
		else return 0;
	}
	for(int i=s;i<e;i++){
		if(a[i]==val){
			idx=i;
			break;
		}
		if(mx<a[i]) mx=a[i];
	}
	if(idx==-1) return val-mx+cal(a, s, e, mx);
	rs=cal(a, s, idx, val);
	re=cal(a, idx+1, e, val);
	return rs+re;
}