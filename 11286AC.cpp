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
	int n, cmd;
	cin >> n;
	priority_queue<int, vi, greater<int> > pq, nq;
	vi res;
	while (n--)
	{
		cin >> cmd;
		if (cmd == 0)
		{
			if (pq.empty() && nq.empty())
				res.push_back(0);
			else if (pq.empty())
			{
				res.push_back(nq.top() * -1);
				nq.pop();
			}
			else if (nq.empty())
			{
				res.push_back(pq.top());
				pq.pop();
			}
			else
			{
				int pval = pq.top(), nval = nq.top();
				if (pval >= nval)
				{
					res.push_back(nq.top() * -1);
					nq.pop();
				}
				else
				{
					res.push_back(pq.top());
					pq.pop();
				}
			}
		}
		else if (cmd > 0)
			pq.push(cmd);
		else
			nq.push(cmd * -1);
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << '\n';
	}
	return 0;
}