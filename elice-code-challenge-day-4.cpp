#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    ll inf = 99999999999;
    cin >> n;
    vector<int> vis(n, 0);
    vector<ll> dp(n, inf);
    vector<vector<int>> adj(n, vector<int>(0));
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    stack<int> st;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(), isleaf = 1;
        st.push(cur);
        vis[cur] = 1;
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int t = adj[cur][i];
            if (vis[t]) continue;
            q.push(t);
            isleaf = 0;
        }
        if (isleaf) dp[cur] = cur + 1;
    }
    while (!st.empty()) {
        int cur = st.top();
        ll min = inf;
        st.pop();
        if (dp[cur] != inf) continue;
        for (int i = 0; i < adj[cur].size(); i++) {
            int tcur = adj[cur][i];
            if (dp[tcur] != inf && min > dp[tcur]) min = dp[tcur];
        }
        dp[cur] = cur + 1 - min;
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] >= 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}