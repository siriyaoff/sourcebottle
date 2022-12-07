#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define MOD 1000007
using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using vl=vector<long long>;
using lld=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    cin>>n>>m>>c;
    vector<vi> ar(n, vi(m, 0));
    vector<vector<vector<vl> > > dp(n, vector<vector<vl> >(m, vector<vl>(c+1, vl(c+1, 0))));
    for(int i=0;i<c;i++){
        int r, cc;
        cin>>r>>cc;
        ar[r-1][cc-1]=i+1;
    }
    if(ar[0][0]) dp[0][0][1][ar[0][0]]=1;
	else dp[0][0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ar[i][j]){
                int curc=ar[i][j];
                if(i>0){
                    for(int k=0;k<curc;k++){
                        for(int l=0;l<curc;l++){
                            dp[i][j][k+1][curc]+=dp[i-1][j][k][l];
                            dp[i][j][k+1][curc]%=MOD;
                        }
                    }
                }
                if(j>0){
                    for(int k=0;k<curc;k++){
                        for(int l=0;l<curc;l++){
                            dp[i][j][k+1][curc]+=dp[i][j-1][k][l];
                            dp[i][j][k+1][curc]%=MOD;
                        }
                    }
                }
            }
            else{
                if(i>0){
                    for(int k=0;k<=c;k++){
                        for(int l=0;l<=c;l++){
                            dp[i][j][k][l]+=dp[i-1][j][k][l];
                            dp[i][j][k][l]%=MOD;
                        }
                    }
                }
                if(j>0){
                    for(int k=0;k<=c;k++){
                        for(int l=0;l<=c;l++){
                            dp[i][j][k][l]+=dp[i][j-1][k][l];
                            dp[i][j][k][l]%=MOD;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<=c;i++){
        int ans=0;
        for(int j=0;j<=c;j++){
            ans+=dp[n-1][m-1][i][j];
            ans%=MOD;
        }
        cout<<ans<<' ';
    }
    return 0;
}
/*
dp[i][j][c][p]=cnt
- (i, j)에 도착했을 때 c개의 오락실을 방문하고 마지막 오락실이 p인 상태
- cnt개의 경우의 수 존재
*/