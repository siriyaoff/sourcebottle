#include <iostream>
#include <set>
#include <vector>
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    set<ll> rs;
    vector<vector<ll> > a(n + 1, vector<ll>(m + 1, 0));
    a[0][0] = 1;
    for (int i = 0; i < r; i++) {
        ll si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;
        if (si > ei || (si == ei && sj > ej)) {
            swap(si, ei);
            swap(sj, ej);
        }
        rs.insert(si * 1e12 + sj * 1e8 + ei * 1e4 + ej);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ll base = i * 1e12 + j * 1e8;
            if (j < m && rs.find(base + i * 1e4 + j + 1) == rs.end()) a[i][j + 1] += a[i][j];
            if (i < n && rs.find(base + (i + 1) * 1e4 + j) == rs.end()) a[i + 1][j] += a[i][j];
        }
    }
    cout << a[n][m];
    return 0;
}