#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;

// in-degree
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi ind(n, 0), ans;
    v<vi> adj(n, vi(0));
    queue<int> q;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        adj[s].push_back(e);
        ind[e]++;
    }
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur + 1);
        for (int i = 0; i < adj[cur].size(); i++) {
            int nv = adj[cur][i];
            ind[nv]--;
            if (ind[nv] == 0) {
                q.push(nv);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

// // DFS
// int tpsort(v<vi> &adj, vi &vis, int v, vi &tv) {
//     vis[v] = 1;
//     for (int i = 0; i < adj[v].size(); i++) {
//         int nv = adj[v][i];
//         if (vis[nv] == 0)
//             tpsort(adj, vis, nv, tv);
//     }
//     tv.push_back(v);
//     return 0;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m;
//     cin >> n >> m;
//     vi vis(n, 0), ans;
//     v<vi> adj(n, vi(0));
//     for (int i = 0; i < m; i++) {
//         int t1, t2;
//         cin >> t1 >> t2;
//         adj[t1 - 1].push_back(t2 - 1);
//     }
//     for (int i = 0; i < n; i++) {
//         if (vis[i] == 0) {
//             tpsort(adj, vis, i, ans);
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     for (int i = 0; i < ans.size(); i++)
//         cout << ans[i] + 1 << ' ';
//     return 0;
// }
