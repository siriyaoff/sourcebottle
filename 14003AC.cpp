#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, lidx;
    cin >> n;
    vi ar(n, 0), lis, ari(n, 0);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    lis.push_back(ar[0]);
    for (int i = 1; i < n; i++) {
        if (lis.back() < ar[i]) {
            lis.push_back(ar[i]);
            ari[i] = lis.size() - 1;
            continue;
        }
        int ci = upper_bound(lis.begin(), lis.end(), ar[i]) - lis.begin();
        if (ci > 0 && lis[ci - 1] == ar[i]) {
            ari[i] = ci - 1;
            continue;
        }
        lis[ci] = ar[i];
        ari[i] = ci;
    }
    cout << lis.size() << endl;
    lidx = lis.size() - 1;
    stack<int> res;
    for (int i = n - 1; i >= 0; i--) {
        if (ari[i] == lidx) {
            res.push(ar[i]);
            lidx--;
            if (lidx == -1) break;
        }
    }
    while (!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
    return 0;
}