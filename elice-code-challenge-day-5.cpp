#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int pow(int x, int p) {
    int r = 1;
    while (p > 0) {
        if (p % 2) r *= x;
        x *= x;
        p /= 2;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(pow(2, n), 0), org, pre, sub;
    for (int i = 0; i < pow(2, n); i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    s.erase(s.begin());
    while (org.size() != n) {
        int elem = s[0];
        sub.push_back(elem);
        for (int i = 0; i < pre.size(); i++)
            sub.push_back(elem + pre[i]);
        sub.erase(unique(sub.begin(), sub.end()), sub.end());
        for (int i = 0; i < sub.size(); i++) {
            int idx = lower_bound(s.begin(), s.end(), sub[i]) - s.begin();
            if (idx == s.size()) continue;
            if (s[idx] == sub[i]) s.erase(s.begin() + idx);
        }
        org.push_back(elem);
        pre.insert(pre.begin(), sub.begin(), sub.end());
        pre.erase(unique(pre.begin(), pre.end()), pre.end());
        sub.clear();
    }
    for (int i = 0; i < org.size(); i++) cout << org[i] << ' ';
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// ll n, m, a, ans;
// vector<ll>v, res;
// multiset<int>now;
// void dfs(ll x, ll sum) {
//     if (x == res.size()) {
//         now.insert(sum + m);
//         return;
//     }
//     dfs(x + 1, sum);
//     dfs(x + 1, sum + res[x]);
// }
// void solve() {
//     cin >> n;
//     for (int i = 0; i < (1 << n); i++) {
//         cin >> a;
//         v.push_back(a);
//     }
//     sort(v.begin(), v.end());
//     for (int i =1; i < v.size(); i++) {

// 		if (now.find(v[i]) == now.end()) {
// 			m = v[i];
// 			dfs(0, 0);
// 			res.push_back(v[i]);
// 		}
// 		now.erase(now.find(v[i]));
//     }
//     for (auto nxt : res)cout << nxt << ' ';
// }
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     solve();
// }