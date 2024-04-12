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
	int n, mcnt = 1;
	int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
	int ar[100][100];
	vector<vi> surf(101, vi(0));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ar[i][j];
			for (int lev = 1; lev < ar[i][j]; lev++)
				surf[lev].push_back(i * 100 + j);
		}
	}
	for (int lev = 1; lev < 101; lev++)
	{
		int rcnt = 0;
		vector<vi> vis(n, vi(n, -1));
		queue<int> q;
		for (int i = 0; i < surf[lev].size(); i++)
		{
			if (vis[surf[lev][i] / 100][surf[lev][i] % 100] != -1)
				continue;
			q.push(surf[lev][i]);
			while (!q.empty())
			{
				int curi = q.front() / 100, curj = q.front() % 100;
				q.pop();
				if (vis[curi][curj] != -1)
					continue;
				vis[curi][curj] = rcnt;
				for (int j = 0; j < 4; j++)
				{
					int ni = curi + di[j], nj = curj + dj[j];
					if (ni > -1 && ni < 100 && nj > -1 && nj < 100)
					{
						if (ar[ni][nj] > lev && vis[ni][nj] == -1)
							q.push(ni * 100 + nj);
					}
				}
			}
			rcnt++;
		}
		if (mcnt < rcnt)
			mcnt = rcnt;
	}
	cout << mcnt;
	return 0;
}