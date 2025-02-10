#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, aidx;
    cin >> n;
    vi lis, ari(n, 0);
    v<vi> ar(n, vi(2, 0));

    for (int i = 0; i < n; i++) {
        cin >> ar[i][0] >> ar[i][1];
    }
    sort(ar.begin(), ar.end());
    lis.push_back(0);
    ari[0] = 0;
    for (int i = 1; i < n; i++) {
        int cur = ar[i][1];
        if (ar[lis.back()][1] < cur) {
            lis.push_back(i);
            ari[i] = lis.size() - 1;
        } else {
            int s = -1, e = lis.size();
            while (s + 1 < e) {
                int mid = (s + e) / 2;
                if (ar[lis[mid]][1] <= cur)
                    s = mid;
                else
                    e = mid;
            }
            lis[e] = i;
            ari[i] = e;
        }
    }

    vi ans;
    aidx = lis.size() - 1;
    for (int i = ar.size() - 1; i >= 0; i--) {
        if (ari[i] == aidx) {
            ans.push_back(ar[i][0]);
            aidx--;
            if (aidx < 0) break;
        }
    }
    reverse(ans.begin(), ans.end());

    aidx = 0;
    ostringstream oss;
    oss << n - ans.size() << '\n';
    for (int i = 0; i < n; i++) {
        if (aidx < ans.size() && ar[i][0] == ans[aidx]) {
            aidx++;
            continue;
        }
        oss << ar[i][0] << '\n';
    }
    cout << oss.str();
    return 0;
}
