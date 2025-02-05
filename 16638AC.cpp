#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

int pow(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 0x01) r *= x;
        x *= x;
        p >>= 1;
    }
    return r;
}

bool isdigit(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

string gen(string s, int msk, int n) {
    int idx = 0;
    vi wrap(n, 0);
    string res = "";
    for (int i = 0; i < n; i++) {
        wrap[i] = msk & 0x01;
        msk >>= 1;
    }
    for (int i = 1; i < n; i++) {
        if (wrap[i - 1] == 1 && wrap[i] == 1) return "";
    }
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]))
            res.push_back(s[i]);
        else {
            if (wrap[idx]) {
                res.insert(res.end() - 1, '(');
                res.push_back(s[i]);
                res.push_back(s[i + 1]);
                res.push_back(')');
                i++;
            } else
                res.push_back(s[i]);
            idx++;
        }
    }
    return res;
}

int getp(char c) {
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*')
        return 2;
    else
        return 3;
}

string trans(string s) {
    int n = s.length();
    string res = "";
    stack<char> op;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i]))
            res.push_back(s[i]);
        else if (s[i] == '(')
            op.push(s[i]);
        else if (s[i] == ')') {
            while (op.top() != '(') {
                res.push_back(op.top());
                op.pop();
            }
            op.pop();
        } else {
            int cp = getp(s[i]);
            if (op.empty() || getp(op.top()) < cp) {
                op.push(s[i]);
            } else {
                while (!op.empty() && getp(op.top()) >= cp) {
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty()) {
        res.push_back(op.top());
        op.pop();
    }
    return res;
}

int calc(string s) {
    int n = s.length();
    stack<long long> st;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            long long n1, n2;
            n2 = st.top();
            st.pop();
            n1 = st.top();
            st.pop();
            if (s[i] == '+')
                st.push(n1 + n2);
            else if (s[i] == '-')
                st.push(n1 - n2);
            else
                st.push(n1 * n2);
        }
    }
    return (int)st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, pn, ans = -1 * pow(2, 31);
    string s;
    cin >> n;
    cin >> s;
    pn = pow(2, n / 2);
    for (int i = 0; i < pn; i++) {
        string ts = gen(s, i, n / 2);
        if (ts == "")
            continue;
        else {
            int t = calc(trans(ts));
            if (ans < t) ans = t;
        }
    }
    cout << ans;
    return 0;
}