#include<cstdio>
int dp[201][201];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<=n;i++) dp[1][i]=1;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) for(int k=0;k<=j;k++) 
		dp[i][j]=(dp[i][j]+dp[i-1][k])%(int)1e9;
	printf("%d", dp[k][n]);
}