#include<cstdio>
#include<utility>
#include<vector>

using namespace std;

int lcs(int ip1, int ip2);

int n;
vector<int> p1, p2;
pair<int, int> dp[1000][1000];

int main()
{
	scanf("%d", &n);
	p1.push_back(-1);
	p2.push_back(-1);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		p1.push_back(t);
	}
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		p2.push_back(t);
	}
	dp[0][0]=make_pair(0, -1);
	dp[0][1]=make_pair(0, -1);
	dp[1][0]=make_pair(0, -1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(p1[i]==p2[j]) if(dp[i-1][j-1].second<p1[i])
			dp[i][j]=make_pair(dp[i-1][j-1].first+1, p1[i]);
		else
			dp[i][j]=(dp[i][j-1].first>dp[i-1][j].first)?dp[i][j-1]:dp[i-1][j];
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			printf("(%d, %d) ", dp[i][j].first, dp[i][j].second);
		printf("\n");
	}
	printf("(%d, %d)", dp[n][n].first, dp[n][n].second);
	return 0;
}