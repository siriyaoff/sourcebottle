#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c, t;
	lld tw, mdp;
	cin>>n>>m>>c;
	vi a(n, 0), b(m, 0);
	vector<vi> w(c, vi(c, 0));
	vector<vector<lld> > dp(n, vector<lld>(m, 0));
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++) cin>>w[i][j];
	}
	for(int i=0;i<n;i++){
		cin>>t;
		a[i]=t-1;
	}
	for(int i=0;i<m;i++){
		cin>>t;
		b[i]=t-1;
	}
	dp[0][0]=w[a[0]][b[0]];
	mdp=dp[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 && j==0) continue;
			tw=0;
			if(i>0) tw=dp[i-1][j];
			if(j>0 && tw<dp[i][j-1]) tw=dp[i][j-1];
			if(tw<w[a[i]][b[j]]) tw=w[a[i]][b[j]];
			if(i>0 && j>0 && tw<w[a[i]][b[j]]+dp[i-1][j-1]) tw=w[a[i]][b[j]]+dp[i-1][j-1];
			dp[i][j]=tw;
			if(tw>mdp) mdp=tw;
		}
	}
	cout<<mdp;
	return 0;
}