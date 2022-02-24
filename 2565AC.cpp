#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define x first
#define y second

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

bool cmp(pii a, pii b){
	return a<b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vi b(n, 0), lis;
	vector<pii> l(n, make_pair(0, 0));
	for(int i=0;i<n;i++)
		cin>>l[i].x>>l[i].y;
	sort(l.begin(), l.end(), cmp);
	for(int i=0;i<n;i++)
		b[i]=l[i].y;
	lis.push_back(b[0]);
	for(int i=1;i<n;i++){
		int idx=lower_bound(lis.begin(), lis.end(), b[i])-lis.begin();
		if(b[i]>lis.back()) lis.push_back(b[i]);
		else lis[idx]=b[i];
	}
	cout<<n-lis.size();
	return 0;
}