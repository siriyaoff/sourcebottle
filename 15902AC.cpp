#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#define MOD 1000000007
using namespace std;
typedef long long lld;
typedef pair<int, int> pi;
typedef vector<int> vi;

lld power(lld n, lld m){
	lld res=1;
	while(m>0){
		if(m%2) res=(res*n)%MOD;
		n=(n*n)%MOD;
		m/=2;
	}
	return res;
}

int main()
{
	int L, n, m, cur;
	vi bstra, bstrb, bstrs;
	lld facto[3001], dp[3001], finv[3001];
	facto[0]=1, facto[1]=1, finv[0]=1, finv[1]=1, dp[0]=1, dp[1]=1;
	for(int i=2;i<3001;i++)	{
		facto[i]=facto[i-1]*i%MOD;
		finv[i]=finv[i-1]*power(i, MOD-2)%MOD;
	}
	
	scanf("%d %d", &L, &n);
	for(int i=0;i<n;i++){
		scanf("%d", &cur);
		if(cur==1) bstra.push_back(1);
		else {
			bstra.push_back(0);
			bstra.push_back(1);
		}
	}
	bstra.erase(bstra.end()-1);
	
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &cur);
		if(cur==1) bstrb.push_back(1);
		else {
			bstrb.push_back(0);
			bstrb.push_back(1);
		}
	}
	bstrb.erase(bstrb.end()-1);
	
	cur=0;
	for(int i=0;i<L-1;i++){
		if(bstra[i]==bstrb[i]){
			if(cur==0) continue;
			bstrs.push_back(cur);
			cur=0;
		}
		else cur++;
	}
	if(cur) bstrs.push_back(cur);
	
	for(int i=2;i<=L;i++){
		for(int j=0;j<i;j+=2){
			lld t=1;
			t=t*dp[j]%MOD*dp[i-j-1]%MOD;
			t=t*facto[i-1]%MOD*finv[i-j-1]%MOD*finv[j]%MOD;
			dp[i]=(dp[i]+t)%MOD;
		}
	}
	
	lld cnt=0, A=1, B=0;
	for(int i=0;i<bstrs.size();i++){
		A=(A*dp[bstrs[i]])%MOD;
		cnt+=bstrs[i];
		A=(A*finv[bstrs[i]])%MOD;
	}
	B=facto[cnt];
	A=(A*B)%MOD;
	printf("%lld %lld", cnt, A);
	return 0;
}