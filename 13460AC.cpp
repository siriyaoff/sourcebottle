#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define v vector

using namespace std;
using vi = vector<int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s = 0, oi, oj;
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    vi vis(10000, 100);
    cin >> n >> m;
    v<v<char>> ar(n, v<char>(m, '#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 'R') {
                s += i * 1000 + j * 100;
                continue;
            }
            if (ar[i][j] == 'B') {
                s += i * 10 + j;
                continue;
            }
            if (ar[i][j] == 'O') {
                oi = i;
                oj = j;
            }
        }
    }
    queue<int> q;
    vis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(), ri, rj, bi, bj;
        q.pop();
        ri = cur / 1000, rj = cur / 100 % 10, bi = cur / 10 % 10, bj = cur % 10;
        for (int i = 0; i < 4; i++) {
            int nri = ri + di[i], nrj = rj + dj[i], nbi = bi + di[i], nbj = bj + dj[i], ncur, boflag = 0, aoflag = 0;
            while (ar[nbi][nbj] != '#') {
                if (ar[nbi][nbj] == 'O') {
                    boflag = 1;
                    break;
                }
                nbi += di[i];
                nbj += dj[i];
            }
            if (boflag) continue;
            nbi -= di[i];
            nbj -= dj[i];
            while (ar[nri][nrj] != '#') {
                if (ar[nri][nrj] == 'O') {
                    aoflag = 1;
                    if (vis[oi * 1000 + oj * 100 + nbi * 10 + nbj] > vis[ri * 1000 + rj * 100 + bi * 10 + bj] + 1) {
                        vis[oi * 1000 + oj * 100 + nbi * 10 + nbj] = vis[ri * 1000 + rj * 100 + bi * 10 + bj] + 1;
                    }
                    break;
                }
                nri += di[i];
                nrj += dj[i];
            }
            if (aoflag) continue;
            nri -= di[i];
            nrj -= dj[i];
            if (nri == nbi && nrj == nbj) {
                if (di[i] == 0) {
                    if (dj[i] == -1) {
                        if (rj < bj)
                            nbj++;
                        else
                            nrj++;
                    } else {
                        if (rj < bj)
                            nrj--;
                        else
                            nbj--;
                    }
                } else {
                    if (di[i] == -1) {
                        if (ri < bi)
                            nbi++;
                        else
                            nri++;
                    } else {
                        if (ri < bi)
                            nri--;
                        else
                            nbi--;
                    }
                }
            }
            ncur = nri * 1000 + nrj * 100 + nbi * 10 + nbj;
            if (vis[ncur] > vis[cur] + 1) {
                vis[ncur] = vis[cur] + 1;
                q.push(ncur);
            }
        }
    }
    s = 100;
    for (int i = oi * 1000 + oj * 100 + 11; i < oi * 1000 + oj * 100 + 99; i++) {
        if (vis[i] < s) s = vis[i];
    }
    if (s > 10)
        cout << -1;
    else
        cout << s;
    return 0;
}
