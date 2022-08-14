#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v, m, j, s, cur;
	cin>>v>>m;
	vi ij(v, -1), is(v, -1);
	vector<vi> adj(v, vi(v, -1));
	vector<pii> res;
	for(int i=0;i<m;i++){
		int s, e, w;
		cin>>s>>e>>w;
		if(adj[--s][--e]!=-1 && adj[s][e]<=w) continue;
		adj[s][e]=w;
		adj[e][s]=w;
	}
	cin>>j>>s;
	ij[--j]=0;
	is[--s]=0;
	queue<int> q;
	q.push(j);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(int i=0;i<v;i++){
			if(adj[cur][i]!=-1 && (ij[i]==-1 || ij[i]>ij[cur]+adj[cur][i])){
				ij[i]=ij[cur]+adj[cur][i];
				q.push(i);
			}
		}
	}
	q.push(s);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(int i=0;i<v;i++){
			if(adj[cur][i]!=-1 && (is[i]==-1 || is[i]>is[cur]+adj[cur][i])){
				is[i]=is[cur]+adj[cur][i];
				q.push(i);
			}
		}
	}
	for(int i=0;i<v;i++){
		if(i==j || i==s) continue;
		res.push_back(make_pair(ij[i]+is[i], i));
	}
	sort(res.begin(), res.end());
	m=10000000;
	for(int i=res.size()-1;i>-1;i--){
		int t=res[i].second;
		if(m>res[i].first) m=res[i].first;
		if(ij[t]>is[t]) res.erase(res.begin()+i);
	}
	for(int i=res.size()-1;i>-1;i--){
		if(res[i].first!=m) res.erase(res.begin()+i);
	}
	if(res.empty()) cout<<-1;
	else{
		int tj=100000000, idx;
		for(int i=0;i<res.size();i++){
			if(tj>ij[res[i].second]){
				tj=ij[res[i].second];
				idx=res[i].second+1;
			}
		}
		cout<<idx;
	}
	return 0;
}