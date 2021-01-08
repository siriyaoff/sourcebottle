// //Brute-force
// #include<bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;

// int n, m;
// bool mz[100][100], t[100][100];
// int v[100][100];
// void f(int ci, int cj, int w){
// 	if(mz[ci][cj]) w++;
// 	if(v[ci][cj]<=w) return;
// 	v[ci][cj]=w;
// 	if(ci==n && cj==m) return;
// 	if(ci>0) f(ci-1, cj, w);
// 	if(cj<m-1) f(ci, cj+1, w);
// 	if(ci<n-1) f(ci+1, cj, w);
// 	if(cj>0) f(ci, cj-1, w);
// }

// int main()
// {
// 	string s;
// 	cin>>m>>n;
// 	for(int i=0;i<n;i++){
// 		getline(cin, s, '\n');
// 		while(s=="") getline(cin, s, '\n');
// 		for(int j=0;j<m;j++) mz[i][j]=s[j]-48;
// 	}
// 	for(int i=0;i<n;i++) for(int j=0;j<m;j++) v[i][j]=10000;
// 	f(0, 0, 0);
// 	cout<<v[n-1][m-1];
// }

//Dijkstra's
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, pair<int, int> > ppii;

int n, m;
int ww[100][100], di[4]={-1, 1, 0, 0}, dj[4]={0, 0, -1, 1};
bool mz[100][100];

int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++){
		char s[101];
		cin>>s;
		for(int j=0;j<m;j++) mz[i][j]=s[j]-48;
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) ww[i][j]=-10000;
	priority_queue<ppii, vector<ppii>> pq;
	ww[0][0]=0;
	pq.push({0, {0, 0}});
	while(!pq.empty()){
		int cw=pq.top().F, ci=pq.top().S.F, cj=pq.top().S.S;
		pq.pop();
		if(ww[ci][cj]>cw) continue;
		for(int i=0;i<4;i++){
			int ni=ci+di[i], nj=cj+dj[i], nw=cw-mz[ni][nj];
			if(ni>-1 && nj>-1 && ni<n && nj<m && ww[ni][nj]<nw){
				pq.push({nw, {ni, nj}});
				ww[ni][nj]=nw;
			}
		}
	}
	cout<<-ww[n-1][m-1];
}

//다익스트라 모드 메모리 어떻게 1100대까지 줄이는지