#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long lld;

int s, m, n, ma[1000], na[1000], p[1000001];
lld cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>m>>n;
	for(int i=0;i<m;i++) cin>>ma[i];
	for(int i=0;i<n;i++) cin>>na[i];
	int ts;
	for(int i=0;i<m;i++){
		ts=0;
		for(int j=0;j<m-1;j++){
			ts+=ma[(i+j)%m];
			p[ts]++;
		}
	}
	p[0]=1;
	p[ts+ma[m-2]]=1;
	for(int i=0;i<n;i++){
		ts=0;
		for(int j=0;j<n-1;j++){
			ts+=na[(i+j)%n];
			if(s-ts>=0) cnt+=p[s-ts];
		}
	}
	if(ts+na[n-2]<=s) cnt+=p[s-ts-na[n-2]];
	cout<<cnt+p[s];
	return 0;
}