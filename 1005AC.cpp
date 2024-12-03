#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/**
 * buttom-up : 리프노드부터 시간 계산, O(N+K)인줄 알았지만, 정점 중첩해서 큐에 등록되기 때문에, O(K^2/4)
 * top-down : w노드부터 시간 계산, O(K^2/4), 둘 다 tle가 나야 맞지만, top-down은 리프노드들에 대한 계산이 빠져서 ac되는 듯
 * dfs+dp : w노드부터 시간 계산, 각 노드들에 대해 dfs 호출하고, 메모이제이션으로 O(N+K)
 * tpsort : 위상정렬 후 w가 나올 때까지 시간 계산, O(N+K)
 */

// tp sort
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n, k, w;
    vector<long long> ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> d(n), ind(n, 0), tp, td;
        vector<long long> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        queue<int> q;
        for (int i = 0; i < n; i++) cin >> d[i];
        for (int i = 0; i < k; i++) {
            int s, e;
            cin >> s >> e;
            s--, e--;
            adj[s].push_back(e);
            ind[e]++;
        }
        cin >> w;
        w--;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        td = d;
        while (!q.empty()) {
            int ci = q.front();
            tp.push_back(ci);
            q.pop();
            for (int i = 0; i < adj[ci].size(); i++) {
                int ni = adj[ci][i];
                ind[ni]--;
                if (vis[ni] == 0 && ind[ni] == 0) {
                    q.push(ni);
                    vis[ni] = 1;
                }
            }
        }
        vis = vector<long long>(n, -1);
        for (int i = 0; i < n; i++) vis[i] = d[i];
        for (int i = 0; i < n; i++) {
            int ci = tp[i];
            if (ci == w) break;
            for (int j = 0; j < adj[ci].size(); j++) {
                int ni = adj[ci][j];
                if (vis[ni] < vis[ci] + d[ni]) vis[ni] = vis[ci] + d[ni];
            }
        }
        if (vis[w] == -1)
            ans.push_back(d[w]);
        else
            ans.push_back(vis[w]);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}
// dfs(top-down)+dp
// int t, n, k, w;
// vector<int> d;
// vector<long long> dp;
// vector<vector<int>> adj;
// long long dfs(int ti) {
//     if (dp[ti] != -1) return dp[ti];
//     long long res = d[ti];
//     for (int i = 0; i < adj[ti].size(); i++) {
//         int ci = adj[ti][i];
//         if (dp[ci] != -1) {
//             if (res < dp[ci] + d[ti]) res = dp[ci] + d[ti];
//         } else {
//             if (res < dfs(ci) + d[ti]) res = dfs(ci) + d[ti];
//         }
//     }
//     return dp[ti] = res;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     vector<int> ans;
//     cin >> t;
//     while (t--) {
//         cin >> n >> k;
//         d = vector<int>(n);
//         dp = vector<long long>(n, -1);
//         adj = vector<vector<int>>(n, vector<int>());
//         for (int i = 0; i < n; i++) cin >> d[i];
//         for (int i = 0; i < k; i++) {
//             int s, e;
//             cin >> s >> e;
//             s--, e--;
//             adj[e].push_back(s);
//         }
//         cin >> w;
//         w--;
//         ans.push_back(dfs(w));
//     }
//     for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
//     return 0;
// }

// top-down(AC)
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int t, n, k, w;
//     vector<long long> ans;
//     cin >> t;
//     while (t--) {
//         cin >> n >> k;
//         vector<long long> d(n), vis(n, 0);
//         vector<vector<int>> adj(n, vector<int>()), radj(n, vector<int>());
//         for (int i = 0; i < n; i++) cin >> d[i];
//         for (int i = 0; i < k; i++) {
//             int s, e;
//             cin >> s >> e;
//             s--, e--;
//             adj[s].push_back(e);
//             radj[e].push_back(s);
//         }
//         cin >> w;
//         w--;
//         queue<long long> q;
//         vis[w] = d[w];
//         for (int i = 0; i < radj[w].size(); i++) {
//             q.push((d[w] + d[radj[w][i]]) * 1000 + radj[w][i]);
//             vis[radj[w][i]] = d[w] + d[radj[w][i]];
//         }
//         while (!q.empty()) {
//             long long curi = q.front() % 1000, curt = q.front() / 1000;
//             q.pop();
//             for (int i = 0; i < radj[curi].size(); i++) {
//                 long long ni = radj[curi][i], nw = curt + d[radj[curi][i]];
//                 if (vis[ni] < nw) {
//                     q.push(nw * 1000 + ni);
//                     vis[ni] = nw;
//                 }
//             }
//         }
//         long long cans = 0;
//         for (int i = 0; i < vis.size(); i++) {
//             if (cans < vis[i]) cans = vis[i];
//         }
//         ans.push_back(cans);
//     }
//     for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
//     return 0;
// }

// bottom-up(TLE)
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int t, n, k, w;
//     vector<long long> ans;
//     cin >> t;
//     while (t--) {
//         cin >> n >> k;
//         vector<int> d(n), isleaf(n, 1);
//         vector<long long> vis(n, 0);
//         vector<vector<int>> adj(n, vector<int>());
//         for (int i = 0; i < n; i++) cin >> d[i];
//         for (int i = 0; i < k; i++) {
//             int s, e;
//             cin >> s >> e;
//             s--, e--;
//             adj[s].push_back(e);
//             isleaf[e] = 0;
//         }
//         cin >> w;
//         w--;
//         queue<long long> q;

//         for (int i = 0; i < n; i++) {
//             if (isleaf[i]) {
//                 q.push(d[i] * 1000 + i);
//                 vis[i] = d[i];
//             }
//         }
//         while (!q.empty()) {
//             long long curi = q.front() % 1000, curt = q.front() / 1000;
//             q.pop();
//             for (int i = 0; i < adj[curi].size(); i++) {
//                 long long ni = adj[curi][i], nw = curt + d[adj[curi][i]];
//                 if (vis[ni] < nw) {
//                     q.push(nw * 1000 + ni);
//                     vis[ni] = nw;
//                 }
//             }
//         }
//         ans.push_back(vis[w]);
//     }
//     for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
//     return 0;
// }