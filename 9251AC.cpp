#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	int mlen, len1 = s1.length() + 1, len2 = s2.length() + 1;
	if (len1 > len2)
		mlen = len1;
	else
		mlen = len2;
	vector<vi> dp(len1, vi(len2, 0));
	for (int i = 0; i < len1; i++)
		dp[i][0] = 0;
	for (int i = 0; i < len2; i++)
		dp[0][i] = 0;

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else if (dp[i - 1][j] > dp[i][j - 1])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	cout << dp[len1 - 1][len2 - 1];
	return 0;
}