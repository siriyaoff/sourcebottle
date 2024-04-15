#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, si, sj, d, f = 1, cnt = 0;
	int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
	int ar[50][50];
	cin >> n >> m >> si >> sj >> d;
	if (d % 2)
		d = 4 - d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
		}
	}
	while (true)
	{
		f = 0;
		if (ar[si][sj] == 0)
		{
			ar[si][sj] = -1;
			cnt++;
		}
		for (int i = 1; i < 5; i++)
		{
			int ni = si + di[(d + i) % 4], nj = sj + dj[(d + i) % 4];
			if (ni > -1 && ni < n && nj > -1 && nj < m && ar[ni][nj] == 0)
			{
				si = ni;
				sj = nj;
				d = (d + i) % 4;
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			int ni = si + -1 * di[d], nj = sj + -1 * dj[d];
			if (ni > -1 && ni < n && nj > -1 && nj < m && ar[ni][nj] != 1)
			{
				si = ni;
				sj = nj;
			}
			else
				break;
		}
	}
	cout << cnt;
	return 0;
}