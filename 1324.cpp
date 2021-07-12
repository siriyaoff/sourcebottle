#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, x, p, dp[1001][1001], dpv[1001][1001];
vector<int> p1, p2;

int main()
{
	cin>>n;
	p1=vi(n+1, 0);
	p2=vi(n+1, 0);
	for(int i=1;i<=n;i++) cin>>p1[i];
	for(int i=1;i<=n;i++) cin>>p2[i];
	for(int i=0;i<=p1.size();i++){
		for(int j=0;j<=p2.size();j++){
			if(i==0 || j==0) dp[i][j]=0;
			else if(p1[i]==p2[j] && dpv[i-1][j-1]<p1[i]){
				dp[i][j]=dp[i-1][j-1]+1;
				dpv[i][j]=p1[i];
			}
			else {
				dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
				if(dp[i][j-1]==dp[i-1][j]) dpv[i][j]=min(dpv[i][j-1], dpv[i-1][j]);
				else dpv[i][j]=(dp[i][j-1]>dp[i-1][j])?dpv[i-1][j]:dpv[i][j-1];
			}
		}
	}
	cout<<dp[p1.size()][p2.size()];
	return 0;
}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++) printf("%d ", dp[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++) printf("%d ", dpv[i][j]);
	// 	printf("\n");
	// }

// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// int N, A[2][1000], dp[1001][1001];

// int trash(int a, int b){
// 	int &ret = dp[a][b];
// 	if(ret != -1) return ret;
// 	if(a == N || b == N) return ret = 0;

// 	ret = 1;
// 	for(int i=a+1; i<N; i++){
// 		if(A[0][a] >= A[0][i]) continue;
// 		for(int j=b+1; j<N; j++){
// 			if(A[0][i] == A[1][j]){
// 				ret = max(ret, trash(i, j)+1);
// 				break;
// 			}
// 		}
// 	}
// 	return ret;
// }

// int main(){
// 	scanf("%d", &N);
// 	for(int i=0; i<2; i++)
// 		for(int j=0; j<N; j++)
// 			scanf("%d", &A[i][j]);
// 	memset(dp, -1, sizeof(dp));
// 	int result = 0;
// 	for(int i=0; i<N; i++){
// 		for(int j=0; j<N; j++){
// 			if(A[0][i] == A[1][j]){
// 				result = max(result, trash(i, j));
// 				break;
// 			}
// 		}
// 	}
// 	printf("%d\n", result);
// }