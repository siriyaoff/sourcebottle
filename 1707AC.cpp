#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> vi;
int isempty(vi& visited);
int put(set<int>& a, set<int>& b, int node, int f);

int main()
{
	int k, v, e;
	vi res;
	scanf("%d", &k);
	while(k--){
		scanf("%d %d", &v, &e);
		vector<vi> adj(v, vector<int>(0));
		set<int> a, b;
		int exitflag=0;
		for(int i=0;i<e;i++){
			int s, t;
			scanf("%d %d", &s, &t);
			adj[--s].push_back(--t);
			adj[t].push_back(s);
		}
		queue<int> q;
		vi visited(v, 0);
		while(isempty(visited)!=-1){
			int s=isempty(visited), f=1;
			q.push(s);
			a.insert(s);
			visited[s]=1;
			while(!q.empty()){
				int cur=q.front();
				f=visited[cur]*-1;
				for(int i=0;i<adj[cur].size();i++){
					int adjv=adj[cur][i];
					exitflag=put(a, b, adjv, f);
					if(visited[adjv]==0){
						q.push(adjv);
						visited[adjv]=f;
					}
					if(exitflag) break;
				}
				q.pop();
				if(exitflag) break;
			}
			if(exitflag) break;
		}
		if(exitflag) res.push_back(0);
		else res.push_back(1);
	}
	
	for(int i=0;i<res.size();i++){
		if(res[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

int isempty(vi& visited){
	for(int i=0;i<visited.size();i++)
		if(visited[i]==0) return i;
	return -1;
}

int put(set<int>& a, set<int>& b, int node, int f){
	if(f==1) a.insert(node);
	else b.insert(node);
	if(a.find(node)!=a.end() && b.find(node)!=b.end()) return 1;
	else return 0;
}