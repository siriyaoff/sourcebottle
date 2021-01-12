#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long lld;

int s, m, n, ts, msi, nsi, ma[1000], na[1000], ms[1000001], ns[1000002];
lld cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>m;
	for(int i=0;i<m;i++) cin>>ma[i];
	cin>>n;
	for(int i=0;i<n;i++) cin>>na[i];
	
	for(int i=0;i<m;i++){
		ts=0;
		for(int j=i;j<m;j++){
			ts+=ma[j];
			ms[++msi]=ts;
		}
	}
	for(int i=0;i<n;i++){
		ts=0;
		for(int j=i;j<n;j++){
			ts+=na[j];
			ns[++nsi]=ts;
		}
	}
	sort(ms+1, ms+msi+1);
	sort(ns+1, ns+nsi+1);
	ms[0]=-1000000001;
	ns[nsi+1]=1000000001;
	int i=msi, j=1, sum=ms[i]+ns[j];
	while(i>0 && j<=nsi){
		if(sum==s){
			int msn=1, nsn=1;
			while(ms[i]==ms[--i]) msn++;
			while(ns[j]==ns[++j]) nsn++;
			cnt+=msn*nsn;
			sum=(lld)ms[i]+ns[j];
		}
		else if(sum>s) while(sum>s) sum=ms[--i]+ns[j];
		else while(sum<s) sum=ms[i]+ns[++j];
	}
	cout<<cnt;
	return 0;
}