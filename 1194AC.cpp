#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;
using ll = long long;
int n, m, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1}, ans = 70000;
v<string> ar;
v<v<v<bool>>> vis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int si, sj;
    ar = v<string>(n);
    vis = v<v<v<bool>>>(n, v<v<bool>>(m, v<bool>(63, false)));
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        for (int j = 0; j < m; j++) {
            if (ar[i][j] == '0')
                si = i, sj = j;
        }
    }
    queue<tuple<int, int, int, char>> q;
    vis[si][sj][0] = true;
    q.push({si, sj, 0, 0});
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        int ci = get<0>(f), cj = get<1>(f), cd = get<2>(f), ck = get<3>(f);
        if (ar[ci][cj] == '1') {
            ans = cd;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ni = ci + di[i], nj = cj + dj[i];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || ar[ni][nj] == '#' || vis[ni][nj][ck]) continue;
            if (ar[ni][nj] >= 'a' && ar[ni][nj] <= 'f') {
                int key = ar[ni][nj] - 'a';
                char tkeys = ck | (0x01 << key);
                vis[ni][nj][tkeys] = true;
                q.push({ni, nj, cd + 1, tkeys});
                continue;
            }
            if (ar[ni][nj] >= 'A' && ar[ni][nj] <= 'F') {
                int key = ar[ni][nj] - 'A';
                if ((ck >> key & 0x01) == 0) continue;
            }
            vis[ni][nj][ck] = true;
            q.push({ni, nj, cd + 1, ck});
        }
    }
    if (ans == 70000)
        cout << -1;
    else
        cout << ans;
    return 0;
}

// // DFS
// int n, m, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1}, ans = 70000;
// v<string> ar;
// vi vis;

// void solve(int si, int sj, char keys) {
//     int cidx = si * 100000 + sj * 1000 + keys;
//     for (int i = 0; i < 4; i++) {
//         int ni = si + di[i], nj = sj + dj[i], nidx;
//         nidx = ni * 100000 + nj * 1000 + keys;
//         if (ni < 0 || ni >= n || nj < 0 || nj >= m || ar[ni][nj] == '#') continue;
//         if (ar[ni][nj] == '1') {
//             if (ans > vis[cidx] + 1)
//                 ans = vis[cidx] + 1;
//             continue;
//         }
//         if (ar[ni][nj] >= 'a' && ar[ni][nj] <= 'f') {
//             int key = ar[ni][nj] - 'a', vidx;
//             char tkeys = keys | (0x01 << key);
//             vidx = ni * 100000 + nj * 1000 + tkeys;
//             if (vis[vidx] > vis[cidx] + 1) {
//                 vis[vidx] = vis[cidx] + 1;
//                 solve(ni, nj, tkeys);
//             }
//         } else if (ar[ni][nj] >= 'A' && ar[ni][nj] <= 'F') {
//             int key = ar[ni][nj] - 'A';
//             if (keys >> key & 0x01 && vis[nidx] > vis[cidx] + 1) {
//                 vis[nidx] = vis[cidx] + 1;
//                 solve(ni, nj, keys);
//             }
//         } else if ((ar[ni][nj] == '.' || ar[ni][nj] == '0') && vis[nidx] > vis[cidx] + 1) {
//             vis[nidx] = vis[cidx] + 1;
//             solve(ni, nj, keys);
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     int si, sj;
//     ar = v<string>(n);
//     vis = vi(10000000, 70000);
//     for (int i = 0; i < n; i++) {
//         cin >> ar[i];
//         for (int j = 0; j < m; j++) {
//             if (ar[i][j] == '0')
//                 si = i, sj = j;
//         }
//     }
//     vis[si * 100000 + sj * 1000] = 0;
//     solve(si, sj, 0);
//     if (ans == 70000)
//         cout << -1;
//     else
//         cout << ans;
//     return 0;
// }
