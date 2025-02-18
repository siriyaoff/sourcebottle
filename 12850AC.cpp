#include <iostream>
#include <vector>
#define v vector
#define NODE 8
#define MOD 1000000007

using namespace std;
using vi = vector<int>;
using ll = long long;

v<v<ll>> mul(v<v<ll>>& m1, v<v<ll>>& m2) {
    int n = m1.size();
    v<v<ll>> res(n, v<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % MOD;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d;
    cin >> d;
    v<v<ll>> r(NODE, v<ll>(NODE, 0)), adj = {{0, 1, 1, 0, 0, 0, 0, 0},
                                             {1, 0, 1, 1, 0, 0, 0, 0},
                                             {1, 1, 0, 1, 1, 0, 0, 0},
                                             {0, 1, 1, 0, 1, 1, 0, 0},
                                             {0, 0, 1, 1, 0, 1, 0, 1},
                                             {0, 0, 0, 1, 1, 0, 1, 0},
                                             {0, 0, 0, 0, 0, 1, 0, 1},
                                             {0, 0, 0, 0, 1, 0, 1, 0}};
    for (int i = 0; i < NODE; i++) r[i][i] = 1;
    while (d) {
        if (d & 0x01) r = mul(r, adj);
        d >>= 1;
        adj = mul(adj, adj);
    }
    cout << r[0][0] << endl;
    return 0;
}
