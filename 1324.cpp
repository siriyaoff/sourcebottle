#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> p1, p2;
vector<vector<pair<int, int>>> dp;
int main()
{
	scanf("%d", &n);
	for(int i=0, x;i<n;i++){
		scanf("%d", &x);
		p1.push_back(x);
	}
	for(int i=0, x;i<n;i++){
		scanf("%d", &x);
		p2.push_back(x);
	}
	for(int i=0;i<n;i++) dp.push_back(vector<pair<int, int>>(n, make_pair(0, 0)));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0 || j==0){
				if(p1[i]==p2[j])
					dp[i][j]=make_pair(1, p1[i]);
				continue;
			}
			
			if(p1[i]==p2[j]){
				if(p1[i]>dp[i-1][j-1].second)
					dp[i][j]=make_pair(dp[i-1][j-1]+1, p1[i]);
				else{
					int im1=dp[i]
				}
			}
		}
	}
	return 0;
}