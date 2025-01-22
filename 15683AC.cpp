#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int n, m;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int p[5][4] = {{0, 1, 0, 0}, {0, 1, 0, 1}, {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 1}};

int span(vector<vi> tar, vi tv, vi st) {
    int curs = 0;
    for (int i = 0; i < st.size(); i++) {
        int curi = tv[i] / 10, curj = tv[i] % 10, curt;
        curt = tar[curi][curj] - 1;
        for (int j = 0; j < 4; j++) {
            int cidx = (j + st[i]) % 4;
            if (p[curt][cidx]) {
                int ni = curi + di[j], nj = curj + dj[j];
                while (ni > -1 && ni < n && nj > -1 && nj < m && tar[ni][nj] != 6) {
                    if (tar[ni][nj] == 0) tar[ni][nj] = -1;
                    ni += di[j];
                    nj += dj[j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tar[i][j] == 0) curs++;
        }
    }
    return curs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int res = 0, f = 0;
    cin >> n >> m;
    vi tv;
    vector<vi> ar(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
            if (ar[i][j] > 0 && ar[i][j] < 6)
                tv.push_back(i * 10 + j);
            else if (ar[i][j] == 0)
                res++;
        }
    }
    vi st(tv.size(), 0);
    while (tv.size()) {
        int idx = tv.size() - 1, curs;
        vector<vi> tar(ar);
        curs = span(tar, tv, st);
        if (curs < res) res = curs;

        st[idx]++;
        while (st[idx] == 4) {
            if (idx == 0) {
                f = 1;
                break;
            }
            st[idx] = 0;
            st[idx - 1]++;
            idx--;
        }
        if (f) break;
    }
    cout << res;
    return 0;
}