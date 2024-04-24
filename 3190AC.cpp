#include <iostream>
#include <utility>
#include <vector>
#include <string>
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
	int n, k, l, x, t = 0, ci = 0, cj = 0, cd = 1; // (0, 1, 2, 3) : (up, right, down, left)
	int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
	char c;
	cin >> n >> k;
	vector<vi> ar(n, vi(n, 0));
	for (int i = 0; i < k; i++)
	{
		int ti, tj;
		cin >> ti >> tj;
		ar[ti - 1][tj - 1] = 1;
	}
	cin >> l;
	queue<int> dirinfo, body;
	body.push(0);
	ar[0][0] = 2;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		if (c == 'D')
			dirinfo.push(x * 10 + 1);
		else
			dirinfo.push(x * 10 + 3);
	}

	while (!dirinfo.empty())
	{
		int x = dirinfo.front() / 10, tcd = (cd + dirinfo.front() % 10 % 4) % 4;
		dirinfo.pop();
		while (++t <= x)
		{
			ci += di[cd];
			cj += dj[cd];
			if (ci < 0 || ci >= n || cj < 0 || cj >= n || ar[ci][cj] == 2)
			{
				cout << t;
				return 0;
			}
			if (ar[ci][cj] == 0)
			{
				int ti = body.front() / 100, tj = body.front() % 100;
				body.pop();
				ar[ti][tj] = 0;
			}
			body.push(ci * 100 + cj);
			ar[ci][cj] = 2;
		}
		t--;
		cd = tcd;
	}
	while (true)
	{
		t++;
		ci += di[cd];
		cj += dj[cd];
		if (ci < 0 || ci >= n || cj < 0 || cj >= n || ar[ci][cj] == 2)
		{
			cout << t;
			return 0;
		}
		if (ar[ci][cj] == 0)
		{
			int ti = body.front() / 100, tj = body.front() % 100;
			body.pop();
			ar[ti][tj] = 0;
		}
		body.push(ci * 100 + cj);
		ar[ci][cj] = 2;
	}
	cout << t;
	return 0;
}