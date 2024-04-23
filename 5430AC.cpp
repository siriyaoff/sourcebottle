#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, rf = -1, ef = 0, si = 0, ei;
		char sp = ',';
		string buf, s, ars;
		vi ar;
		istringstream iss;
		cin >> s >> n >> ars;
		if (ars.length() > 2)
		{
			ars = ars.substr(1, ars.length() - 2);
			istringstream iss(ars);
			while (getline(iss, buf, sp))
			{
				ar.push_back(stoi(buf));
			}
		}

		ei = ar.size();
		sp = 'R';
		iss = istringstream(s);
		while (getline(iss, buf, sp))
		{
			if (buf.length() > 0)
			{
				if (rf == -1)
					si += buf.length();
				else
					ei -= buf.length();
				if (si > ei)
				{
					cout << "error";
					ef = 1;
					break;
				}
			}
			rf *= -1;
		}
		if (count(s.begin(), s.end(), 'R') % 2 == 0)
			rf = -1;
		else
			rf = 1;
		if (ef == 0)
		{
			cout << '[';
			if (rf == 1)
			{
				for (int i = ei - 1; i > si; i--)
					cout << ar[i] << ',';
				if (si < ei)
					cout << ar[si];
			}
			else
			{
				for (int i = si; i < ei - 1; i++)
					cout << ar[i] << ',';
				if (si < ei)
					cout << ar[ei - 1];
			}
			cout << "]";
		}
		if (t)
			cout << '\n';
	}
	return 0;
}