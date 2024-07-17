#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n, 0), b(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] >= st.top()) st.pop();
        if (st.empty())
            b[i] = -1;
        else
            b[i] = st.top();
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++) cout << b[i] << ' ';

    // b[n - 1] = -1;
    // for (int i = n - 2; i >= 0; i--) {
    //     if (a[i] < a[i + 1])
    //         b[i] = a[i + 1];
    //     else {
    //         for (int j = i + 1; j < n; j++) {
    //             if (a[i] < b[j]) {
    //                 b[i] = b[j];
    //                 break;
    //             }
    //             if (a[i] >= a[j] && b[j] == -1) {
    //                 b[i] = -1;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++) cout << b[i] << ' ';
    return 0;
}