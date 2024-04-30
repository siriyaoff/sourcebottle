#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, ans = 0;
	cin >> n >> m >> x;
	x--;
	vi ttime(n, 0);
	vector<vi> adj(n, vi(0));
	for (int i = 0; i < m; i++)
	{
		int w, s, e;
		cin >> s >> e >> w;
		s--, e--;
		adj[s].push_back(e * 1000 + w);
	}
	vi vis(n, 1000001);
	queue<int> q;
	q.push(x);
	vis[x] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int adjv = adj[cur][i] / 1000, w = adj[cur][i] % 1000;
			if (vis[adjv] >= vis[cur] + w)
			{
				vis[adjv] = vis[cur] + w;
				q.push(adjv);
			}
		}
	}
	for (int i = 0; i < n; i++)
		ttime[i] += vis[i];

	vector<vi> radj(n, vi(0));
	vis = vi(n, 1000001);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			radj[adj[i][j] / 1000].push_back(i * 1000 + adj[i][j] % 1000);
	q.push(x);
	vis[x] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < radj[cur].size(); i++)
		{
			int adjv = radj[cur][i] / 1000, w = radj[cur][i] % 1000;
			if (vis[adjv] >= vis[cur] + w)
			{
				vis[adjv] = vis[cur] + w;
				q.push(adjv);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		ttime[i] += vis[i];
		if (ans < ttime[i])
			ans = ttime[i];
	}
	cout << ans;
	return 0;
}