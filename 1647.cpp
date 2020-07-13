#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> wnd; //(weight, dest)

class edge{
	public:
	int s, w, d;
	edge(){}
	edge(int ps, int pw, int pd){s=ps;w=pw;d=pd;}
	void change(int ps, int pw, int pd){s=ps;w=pw;d=pd;}
};

struct cmpPair{
	bool operator()(edge p1, edge p2){
		return p1.w>p2.w;
	}
};

int main()
{
	int n, m;
	vector<vector<wnd>> G;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		vector<wnd> t;
		G.push_back(t);
	}
	for(int i=0, s, d, w;i<m;i++){
		scanf("%d %d %d", &s, &d, &w);
		G[--s].push_back(make_pair(w, --d));
		G[d].push_back(make_pair(w, s));
	}
	vector<int> visited(n, 0), key(n, 987654321), parents;
	for(int i=0;i<n;i++) parents.push_back(i);
	key[0]=0;
	parents[0]=0;
	priority_queue<edge, vector<edge>, cmpPair> curkey, included;
	curkey.push(edge(0, 0, 0));
	
	int totw=0;
	while(!curkey.empty()){
		edge e;
		int curv=-1;
		e=curkey.top();
		curkey.pop();
		curv=e.d;
		if(key[curv]!=e.w || visited[curv]) continue;
		included.push(e);
		visited[curv]=1;
		parents[curv]=e.s;
		totw+=e.w;
		for(int i=0;i<G[curv].size();i++){
			int dest=G[curv][i].second, neww=G[curv][i].first;
			if(visited[dest]) continue;
			if(key[dest]>neww){
				key[dest]=neww;
				curkey.push(edge(curv, neww, dest));
			}
		}
	}
	
	int max=0;
	while(!included.empty()){
		max=included.top().w;
		included.pop();
	}
	printf("%d", totw-max);
	return 0;
}