#include <algorithm>
#include <iostream>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, n, w;
    cin >> tc;
    while (tc--) {
        cin >> n >> w;
        v<vi> ar(2, vi(n, 0));
        v<v<vi>> dp(4, v<vi>(n, vi(5, 9999999)));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) cin >> ar[i][j];
        }
        dp[0][0][0] = 2;
        if (ar[0][0] + ar[1][0] <= w) dp[0][0][1] = 1;
        if (ar[0][n - 1] + ar[0][0] <= w && n > 1) {
            dp[1][0][0] = 2;
            if (ar[0][0] + ar[1][0] <= w) dp[1][0][1] = 1;
            dp[1][0][2] = 1;
        }
        if (ar[1][n - 1] + ar[1][0] <= w && n > 1) {
            dp[2][0][0] = 2;
            if (ar[0][0] + ar[1][0] <= w) dp[2][0][1] = 1;
            dp[2][0][3] = 1;
        }
        if (dp[1][0][2] == 1 && dp[2][0][3] == 1 && n > 1) {
            dp[3][0][0] = 2;
            if (ar[0][0] + ar[1][0] <= w) dp[3][0][1] = 1;
            dp[3][0][2] = 1;
            dp[3][0][3] = 1;
            dp[3][0][4] = 0;
        }

        for (int c = 0; c < 4; c++) {
            for (int i = 1; i < n; i++) {
                bool f0 = ar[0][i - 1] + ar[0][i] <= w, f1 = ar[1][i - 1] + ar[1][i] <= w;
                dp[c][i][0] = *min_element(dp[c][i - 1].begin(), dp[c][i - 1].end()) + 2;
                if (ar[0][i] + ar[1][i] <= w) dp[c][i][1] = dp[c][i][0] - 1;
                if (f0) dp[c][i][2] = min(dp[c][i - 1][0], dp[c][i - 1][3]) + 1;
                if (f1) dp[c][i][3] = min(dp[c][i - 1][0], dp[c][i - 1][2]) + 1;
                if (f0 && f1) dp[c][i][4] = dp[c][i - 1][0];
            }
        }

        int res = *min_element(dp[0][n - 1].begin(), dp[0][n - 1].end());
        res = min({res, dp[1][n - 1][0], dp[1][n - 1][3], dp[2][n - 1][0], dp[2][n - 1][2], dp[3][n - 1][0]});
        cout << res << '\n';
    }
    return 0;
}
