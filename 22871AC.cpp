#include<iostream>
#include<vector>
#define abs(x) (x>0?x:-x)

using namespace std;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vi a(n, 0);
	vector<lld> dp(n, 5000000000);
	dp[0]=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			lld t=(lld)(i-j)*(1+abs((a[i]-a[j])));
			if(t<dp[j]) t=dp[j];
			if(dp[i]>t) dp[i]=t;
		}
	}
	cout<<dp[n-1];
	return 0;
}