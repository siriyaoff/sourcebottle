#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define MOD 1000000
using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<vector<vi> > d(n+1, vector<vi>(2, vi(3, 0)));// 0:O, 1:L, 2:A
	d[1][0][0]=d[1][0][2]=d[1][1][1]=1;
	if(n>1){
		d[2][0][0]=d[2][0][2]=d[2][1][1]=2;
		d[2][1][0]=d[2][1][2]=1;
	}
	for(int i=3;i<n+1;i++){
		d[i][0][0]=(d[i-1][0][0]+d[i-1][0][2])%MOD;
		d[i][1][0]=(d[i-1][1][0]+d[i-1][1][1]+d[i-1][1][2])%MOD;
		d[i][1][1]=(d[i-1][0][0]+d[i-1][0][2])%MOD;
		d[i][0][2]=(d[i-1][0][0]+d[i-2][0][0])%MOD;
		d[i][1][2]=(d[i-1][1][0]+d[i-1][1][1]+d[i-2][1][0]+d[i-2][1][1])%MOD;
	}
	cout<<(d[n][0][0]+d[n][0][2]+d[n][1][0]+d[n][1][1]+d[n][1][2])%MOD;
	return 0;
}