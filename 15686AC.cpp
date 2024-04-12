#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int pow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 0x01)
			r *= x;
		x *= x;
		p >>= 1;
	}
	return r;
}

int calones(int n)
{
	int r = 0;
	while (n)
	{
		if (n & 0x01)
			r++;
		n >>= 1;
	}
	return r;
}

int abs(int n)
{
	if (n > 0)
		return n;
	else
		return -1 * n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, mindis = 10000, chkcnt = 0, hcnt = 0, cases, ones = 0, curi = -1;
	int ar[50][50], chk[13][2], ho[100][2];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ar[i][j];
			if (ar[i][j] == 1)
			{
				ho[hcnt][0] = i;
				ho[hcnt++][1] = j;
			}
			else if (ar[i][j] == 2)
			{
				chk[chkcnt][0] = i;
				chk[chkcnt++][1] = j;
			}
		}
	}
	cases = pow(2, chkcnt);
	while (++curi < cases)
	{
		if (calones(curi) > m)
			continue;

		int cdis = 0, tidx = 0;
		vi curcase(chkcnt, 0);
		for (int i = curi; i > 0; i >>= 1)
		{
			curcase[tidx++] = i & 0x01;
		}
		for (int i = 0; i < hcnt; i++)
		{
			int curhdis = 100;
			for (int j = 0; j < chkcnt; j++)
			{
				if (curcase[j] == 0)
					continue;
				int tdis = abs(ho[i][0] - chk[j][0]) + abs(ho[i][1] - chk[j][1]);
				if (tdis < curhdis)
					curhdis = tdis;
			}
			cdis += curhdis;
		}
		if (mindis > cdis)
			mindis = cdis;
	}
	cout << mindis;
	return 0;
}