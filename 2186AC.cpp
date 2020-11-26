#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, a[100][100], pidx, p[80], di[4]={-1, 0, 1, 0}, dj[4]={0, -1, 0, 1}, res=0;
	string s;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		getline(cin, s, '\n');
		while(s=="") getline(cin, s, '\n');
		for(int j=0;j<m;j++) a[i][j]=s[j]-'A';
	}
	getline(cin, s, '\n');
	while(s=="") getline(cin, s, '\n');
	pidx=s.length();
	for(int i=0;i<pidx;i++) p[i]=s[i]-'A';
	
	//dp, pidx-1부터 재귀로 탐색해나가면 dp돌릴 원소 탐색을 한 번만 해도 됨
	int dp[100][100][80];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		if(a[i][j]==p[0]) dp[i][j][0]=1;
		else dp[i][j][0]=0;
		for(int kk=1;kk<pidx;kk++) dp[i][j][kk]=0;
	}
	for(int kk=0;kk<pidx-1;kk++) for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		if(a[i][j]!=p[kk]) continue;
		for(int i2=1;i2<=k;i2++) for(int j2=0;j2<4;j2++){
			int ti=i+i2*di[j2], tj=j+i2*dj[j2];
			if(-1<ti && ti<n && -1<tj && tj<m)
				if(a[ti][tj]==p[kk+1])
					dp[ti][tj][kk+1]+=dp[i][j][kk];
		}
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		res+=dp[i][j][pidx-1];
	cout<<res;
	/*
	
	//bfs, brute-force	MLE
	queue<pair<int, int>> q;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		if(a[i][j]==p[0]) q.push({i*100+j, 0});
	while(!q.empty()){
		int ci=q.front().first/100, cj=q.front().first%100, mv=q.front().second;
		q.pop();
		if(mv==pidx-1){
			res++;
			continue;
		}
		for(int i=1;i<=k;i++) for(int j=0;j<4;j++){
			int ti=ci+i*di[j], tj=cj+i*dj[j];
			if(-1<ti && ti<n && -1<tj && tj<m)
				if(a[ti][tj]==p[mv+1])
					q.push({ti*100+tj, mv+1});
		}
	}
	cout<<res;
	/**/
}
