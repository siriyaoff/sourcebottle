#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using lld = long long;

int getp(char o) {
    if (o == '*' || o == '/')
        return 1;
    if (o == '+' || o == '-')
        return 2;
    if (o == '(') return 3;
}

int isOp(char c) {
    if (c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')')
        return 1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string m, ans;
    stack<char> st;
    cin >> m;
    for (int i = 0; i < m.length(); i++) {
        if (isOp(m[i])) {
            if (st.empty() || m[i] == '(')
                st.push(m[i]);
            else if (m[i] == ')') {
                while (st.top() != '(') {
                    ans.insert(ans.end(), st.top());
                    st.pop();
                }
                st.pop();
            } else if (getp(st.top()) > getp(m[i]))
                st.push(m[i]);
            else if (getp(st.top()) == getp(m[i])) {
                ans.insert(ans.end(), st.top());
                st.pop();
                st.push(m[i]);
            } else {
                while (!st.empty() && (getp(st.top()) <= getp(m[i]))) {
                    ans.insert(ans.end(), st.top());
                    st.pop();
                }
                st.push(m[i]);
            }
        } else
            ans.insert(ans.end(), m[i]);
    }
    while (!st.empty()) {
        ans.insert(ans.end(), st.top());
        st.pop();
    }
    cout << ans << '\n';
    return 0;
}