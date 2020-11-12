#include<cstdio>
#include<vector>
#include<deque>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> p(n+1, 0);
	p[1]=1;
	deque<pii> d;
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(p[a]) p[b]=a;
		else if(p[b]) p[a]=b;
		else d.push_back({a, b});
	}
	
	// while(!d.empty()){		//TLE
	// 	deque<pii> d2;
	// 	d2.swap(d);
	// 	for(int i=0;i<d2.size();i++){
	// 		int a=d2[i].first, b=d2[i].second;
	// 		if(p[a]) p[b]=a;
	// 		else if(p[b]) p[a]=b;
	// 		else d.push_back({a, b});
	// 	}
	// }
	while(!d.empty()){		//40ms
        deque<pii> r;
        r.swap(d);
        while(!r.empty()){
            int a=r.front().first,b=r.front().second;r.pop_front();
            if(p[a])p[b]=a;
            else if(p[b])p[a]=b;
            else d.push_front({a,b});
        }
    }
	
	for(int i=2;i<=n;i++) printf("%d\n", p[i]);
	return 0;
}

// #include<cstdio>
// #include<vector>
// #include<queue>
// #include<algorithm>
// #include<utility>
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int, int> pii;

// int main()
// {
// 	int n;
// 	scanf("%d", &n);
// 	vi p(n+1), v(n+1, 0);
// 	vector<pii> e;
// 	for(int i=1;i<n;i++){
// 		int s, z;
// 		scanf("%d %d", &s, &z);
// 		e.push_back(make_pair(s, z));
// 		e.push_back(make_pair(z, s));
// 	}
// 	sort(e.begin(), e.end());
// 	queue<int> q;
// 	auto lb=lower_bound(e.begin(), e.end(), make_pair(1, 1)), ub=upper_bound(e.begin(), e.end(), make_pair(1, n));
// 	v[1]=1;
// 	for(auto it=lb;it!=ub;++it){
// 		p[it->second]=it->first;
// 		q.push(it->second);
// 		v[it->second]=1;
// 	}
// 	while(!q.empty()){
// 		int cur=q.front(), f=1;
// 		lb=lower_bound(e.begin(), e.end(), make_pair(cur, 1)), ub=upper_bound(e.begin(), e.end(), make_pair(cur, n));
// 		for(auto it=lb;it!=ub;++it){
// 			if(v[it->second]==0){
// 				p[it->second]=it->first;
// 				q.push(it->second);
// 				f=0;
// 				v[it->second]=1;
// 			}
// 		}
// 		if(f) q.pop();
// 	}
// 	for(int i=2;i<=n;i++) printf("%d\n", p[i]);
// 	return 0;
// }

/*
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];

void dfs(int i, int par)
{
	p[i] = par;
	for (int x : adj[i])
		if (x != par)
			dfs(x, i);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i;
	cin >> n;
	for (i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (i = 2; i <= n; i++)
		cout << p[i] << '\n';
}
*/