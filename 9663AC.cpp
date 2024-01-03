#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int ar[15][15];
int cstt[15];
int n;

int solve(int ni, int nj)
{
	int cnt = 0;
	if (ni + 1 == n)
		return 1;
	cstt[nj] = 1;
	ar[ni][nj] = ni;
	for (int i = 0; i < n; i++)
	{
		if (cstt[i] == 0)
		{
			int f = 0, nni = ni + 1, nnj = i;
			for (int j = -n; j < n; j++)
			{
				if (nni + j >= 0 && nni + j < n && nnj + j >= 0 && nnj + j < n && ar[nni + j][nnj + j] != -1)
					f = 1;
				if (nni - j >= 0 && nni - j < n && nnj + j >= 0 && nnj + j < n && ar[nni - j][nnj + j] != -1)
					f = 1;
				if (f == 1)
					break;
			}
			if (f == 0)
				cnt += solve(ni + 1, i);
		}
	}
	cstt[nj] = 0;
	ar[ni][nj] = -1;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ar[i][j] = -1;
		cstt[i] = 0;
	}
	for (int i = 0; i < n; i++)
		cnt += solve(0, i);
	cout << cnt;
	return 0;
}