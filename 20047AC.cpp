#include<iostream>
#include<vector>
#include<string>

using namespace std;
using vi=vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, f=0;
	char ca, cb;
	string s, t, r;
	cin>>n>>s>>t>>a>>b;
	ca=s[a];
	cb=s[b];
	r=s;
	r.erase(b, 1);
	r.erase(a, 1);
	vector<vi> dp(n, vi(3, -1));
	if(r[0]==t[0]) dp[0][0]=1;
	else dp[0][0]=0;
	if(ca==t[0]) dp[0][1]=1;
	else dp[0][1]=0;
	dp[0][2]=0;
	for(int i=1;i<n;i++){
		if(dp[i-1][0] && r[i]==t[i]) dp[i][0]=1;
		else dp[i][0]=0;
		if((dp[i-1][0] && ca==t[i]) || (dp[i-1][1] && r[i-1]==t[i])) dp[i][1]=1;
		else dp[i][1]=0;
		if((dp[i-1][1] && cb==t[i]) || (dp[i-1][2] && r[i-2]==t[i])) dp[i][2]=1;
		else dp[i][2]=0;
	}
	if(dp[n-1][0] || dp[n-1][1] || dp[n-1][2]) cout<<"YES";
	else cout<<"NO";
	return 0;
}