#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int getp(vi &ar, int n)
{
	if (ar[n] == n)
		return n;
	else
		return ar[n] = getp(ar, ar[n]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cnt = 0, tnum;
	cin >> n >> m;
	cin >> tnum;
	vi par(n, 0), tar(n, 0), tpar(n, 0);
	vector<vi> parties(m, vi(0));
	for (int i = 0; i < n; i++)
		par[i] = i;
	for (int i = 0; i < tnum; i++)
	{
		int t;
		cin >> t;
		tar[t - 1] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int p = 51;
		cin >> tnum;
		parties[i] = vi(tnum, 0);
		for (int j = 0; j < tnum; j++)
		{
			int t;
			cin >> t;
			parties[i][j] = --t;
			t = getp(par, t);
			if (p > t)
				p = t;
		}
		for (int j = 0; j < tnum; j++)
		{
			par[getp(par, parties[i][j])] = p;
		}
	}
	for (int i = 0; i < n; i++)
		if (tar[i] == 1)
			tpar[getp(par, i)] = 1;
	for (int i = 0; i < m; i++)
	{
		int tf = 0;
		for (int j = 0; j < parties[i].size(); j++)
		{
			if (tpar[getp(par, parties[i][j])] == 1)
			{
				tf = 1;
				break;
			}
		}
		if (tf == 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}