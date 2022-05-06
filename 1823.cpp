#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int n, v[2001], dp[2001][2001];

int solve(int l, int r, int day){
	if(l>r) return 0;
	int &ret=dp[l][r];
	if(ret!=-1) return ret;
	return ret=max(v[l]*day+solve(l+1, r, day+1), v[r]*day+solve(l, r-1, day+1));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	memset(dp, -1, sizeof(dp));
	cout<<solve(0, n-1, 1);
	return 0;
}
