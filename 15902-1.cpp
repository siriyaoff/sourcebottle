#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#define MOD 1000000007
using namespace std;
typedef long long ulld;
typedef pair<int, int> pi;
ulld ct[3001][3001], facto[1501], dp[3001];

ulld ncr(int n, int r){
	if(r==0) return 1;
	if(n==0) return 1;
	if(ct[n][r]!=0) return ct[n][r];
	return ct[n][r]=(ncr(n-1, r-1)+ncr(n-1, r))%MOD;
}

ulld f(int n){
	if(n==0) return 1;
	if(n==1) return 1;
	if(facto[n]!=0) return facto[n];
	ulld t=(n*f(n-1))%MOD;
	return facto[n]=t;
}

ulld d(int n){
	if(dp[n]!=0) return dp[n];
	ulld res=0, t;
	for(int i=0;i<n;i+=2){
		t=(d(i)*d(n-1-i))%MOD;
		t=(t*ncr(n-1, i))%MOD;
		res=(res+t)%MOD;
	}
	return dp[n]=res;
}

ulld power(ulld n, ulld m){
	ulld res=1;
	while(m>0){
		if(m%2) res=(res*n)%MOD;
		n=(n*n)%MOD;
		m/=2;
	}
	return res;
}

int main()
{
	int L, n, m;
	for(int i=0;i<3001;i++) for(int j=0;j<3001;j++) ct[i][j]=0;
	for(int i=0;i<3001;i++)	ct[i][i]=1, ct[i][1]=i, dp[i]=0;
	for(int i=0;i<1501;i++) facto[i]=0;
	facto[1]=1, facto[2]=2;
	scanf("%d %d", &L, &n);
	vector<int> a(n, 0), bitsa;
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		if(a[i]==2) bitsa.push_back(0);
		bitsa.push_back(1);
	}
	scanf("%d", &m);
	vector<int> b(m, 0), bitsb;
	for(int i=0;i<m;i++){
		scanf("%d", &b[i]);
		if(b[i]==2) bitsb.push_back(0);
		bitsb.push_back(1);
	}
	bitsa.erase(bitsa.end()-1);
	bitsb.erase(bitsb.end()-1);
	int fl=0, cor;
	vector<pi> bits;//bits : [a, b+1)
	for(int i=0;i<L;i++){
		if(fl && bitsa[i]==bitsb[i]) fl=0, bits.push_back(make_pair(cor, i));
		if(!fl && bitsa[i]!=bitsb[i]) fl=1, cor=i;
	}
	if(fl) bits.push_back(make_pair(cor, L));
	
	ulld A=1, B=0, C=1;
	vector<int> lk;
	for(int i=0;i<bits.size();i++) lk.push_back(bits[i].second-bits[i].first);
	dp[0]=1, dp[1]=1;
	for(int i=0;i<lk.size();i++){
		A=(A*d(lk[i]))%MOD;
		B=B+lk[i];
		C=(C*f(lk[i]))%MOD;
	}
	B=f(B);
	A=(A*B)%MOD;
	C=power(C, MOD-2);
	if(C<0) C+=MOD;
	A=(A*C)%MOD;
	
	int T=0;
	for(int i=0;i<lk.size();i++) T+=lk[i];
	printf("%d %d", T, A);
	return 0;
}