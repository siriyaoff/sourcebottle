#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> Pair;//first : weight, second : linked node
typedef vector<pair<int, int> > NODE;
int v, e;

struct cmpPair{
	bool operator()(Pair p1, Pair p2){
		return p1.first>p2.first;
	}
};

priority_queue<Pair, vector<Pair>, cmpPair> weights;
vector<NODE> g;

int main()
{
	scanf("%d %d", &v, &e);
	for(int i=0;i<v;i++){
		NODE t;
		g.push_back(t);
	}
	for(int i=0;i<e;i++){
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		g[--v1].push_back(make_pair(w, --v2));
		g[v2].push_back(make_pair(w, v1));
	}
	vector<int> weight;
	for(int i=0;i<v;i++){
		sort(g[i].begin(), g[i].end());
		weights.push(make_pair(987654321, i));
		weight.push_back(987654321);
	}
	
	int cur, totW=0;
	vector<int> visited(v, 0), parent(v, -1);
	Pair curP=weights.top();
	weights.pop();
	curP.first=0;
	weights.push(curP);
	cur=curP.second;
	weight[cur]=0;
	parent[cur]=cur;
	
	while(!weights.empty()){
		curP=weights.top();
		weights.pop();
		cur=curP.second;
		if(curP.first!=weight[cur]) continue;
		visited[cur]=1;
		totW+=weight[cur];
		for(int i=0;i<g[cur].size();i++){
			Pair adj=g[cur][i];
			if(visited[adj.second]) continue;
			int neww=adj.first;
			if(neww<weight[adj.second]){
				weight[adj.second]=neww;
				weights.push(make_pair(neww, adj.second));
				parent[adj.second]=cur;
			}
		}
	}
	
	printf("%d", totW);
	return 0;
}