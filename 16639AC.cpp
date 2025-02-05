#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;

// dp
long long calc(long long n1, long long n2, char op) {
    if (op == '+')
        return n1 + n2;
    else if (op == '-')
        return n1 - n2;
    else
        return n1 * n2;
}

int main() {
    int n, nn;
    string str;
    cin >> n;
    cin >> str;
    nn = n / 2 + 1;
    v<v<long long>> dmax(nn, v<long long>(nn, -3486784410)), dmin(nn, v<long long>(nn, 3486784410));
    for (int i = 0; i < nn; i++) {
        dmax[i][i] = str[i * 2] - '0';
        dmin[i][i] = str[i * 2] - '0';
    }
    for (int d = 1; d < nn; d++) {
        for (int s = 0; s < nn - d; s++) {
            for (int pv = 0; pv < d; pv++) {
                char op = str[(s + pv) * 2 + 1];
                v<long long> tv;
                tv.push_back(calc(dmax[s][s + pv], dmax[s + pv + 1][s + d], op));
                tv.push_back(calc(dmax[s][s + pv], dmin[s + pv + 1][s + d], op));
                tv.push_back(calc(dmin[s][s + pv], dmax[s + pv + 1][s + d], op));
                tv.push_back(calc(dmin[s][s + pv], dmin[s + pv + 1][s + d], op));
                sort(tv.begin(), tv.end());
                if (dmax[s][s + d] < tv[3]) dmax[s][s + d] = tv[3];
                if (dmin[s][s + d] > tv[0]) dmin[s][s + d] = tv[0];
            }
        }
    }
    cout << dmax[0][nn - 1];
    return 0;
}

// //DFS
// int pow(int x, int p) {
//     int r = 1;
//     while (p) {
//         if (p & 0x01) r *= x;
//         x *= x;
//         p >>= 1;
//     }
//     return r;
// }

// bool isdigit(char c) {
//     if (c >= '0' && c <= '9')
//         return true;
//     else
//         return false;
// }

// int solve(vector<long long> ts) {
//     int res = -1 * pow(2, 31), tr;
//     if (ts.size() == 1) return ts[0];
//     for (int i = 1; i < ts.size(); i += 2) {
//         int n1 = ts[i - 1], n2 = ts[i + 1];
//         vector<long long> tts(0);
//         tts.insert(tts.end(), ts.begin(), ts.begin() + i - 1);
//         if (ts[i] == -1) {
//             tts.push_back(n1 + n2);
//         } else if (ts[i] == 0)
//             tts.push_back(n1 - n2);
//         else
//             tts.push_back(n1 * n2);
//         tts.insert(tts.end(), ts.begin() + i + 2, ts.end());
//         tr = solve(tts);
//         if (res < tr) res = tr;
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int n;
//     vector<long long> ts;
//     string s;
//     cin >> n;
//     cin >> s;
//     for (int i = 0; i < s.length(); i++) {
//         if (isdigit(s[i])) {
//             ts.push_back(s[i] - '0');
//         } else if (s[i] == '+')
//             ts.push_back(-1);
//         else if (s[i] == '-')
//             ts.push_back(0);
//         else
//             ts.push_back(1);
//     }
//     cout << solve(ts);
//     return 0;
// }