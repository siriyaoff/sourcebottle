#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n;
    vi dp(n, 0);
    vector<vi> al(n, vi(0));
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == -1) continue;
        al[t].push_back(i);
    }
    for (int i = n - 1; i > -1; i--) {
        if (al[i].size() == 0) {
            dp[i] = 0;
            continue;
        }
        int m = 0, cnt = 0;
        vi tv;
        for (int j = 0; j < al[i].size(); j++) {
            tv.push_back(dp[al[i][j]]);
        }
        sort(tv.begin(), tv.end());
        for (int j = 0; j < tv.size(); j++) {
            tv[j] += tv.size() - j;
            if (m < tv[j]) m = tv[j];
        }
        dp[i] = m;
    }
    cout << dp[0];
    return 0;
}