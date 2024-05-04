#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, n, m, w, s, e, t;
    cin >> tc;
    vector<string> ans;
    while (tc--) {
        cin >> n >> m >> w;
        vi sp(n, 99999);
        vector<vi> adje, adjv(n, vi(n, 99999));
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            s--, e--;
            if (adjv[s][e] > t) adjv[s][e] = t;
            if (adjv[e][s] > t) adjv[e][s] = t;
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            s--, e--;
            if (adjv[s][e] > -t) adjv[s][e] = -t;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjv[i][j] != 99999) {
                    vi tv;
                    tv.push_back(i);
                    tv.push_back(j);
                    tv.push_back(adjv[i][j]);
                    adje.push_back(tv);
                }
            }
        }
        sp[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < adje.size(); j++) {
                int curs = adje[j][0], cure = adje[j][1], w = adje[j][2];
                if (sp[cure] > sp[curs] + w) sp[cure] = sp[curs] + w;
            }
        }
        n = 1;
        for (int i = 0; i < adje.size(); i++) {
            int curs = adje[i][0], cure = adje[i][1], w = adje[i][2];
            if (sp[cure] > sp[curs] + w) {
                ans.push_back("YES");
                n = 0;
                break;
            }
        }
        if (n) ans.push_back("NO");
    }
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << '\n';
    cout << ans.back();
    return 0;
}