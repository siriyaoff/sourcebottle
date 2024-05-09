#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, si, sj, ss = 2, seat = 0, ans = 0, sp, spi, spj;
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    cin >> n;
    vector<vi> ar(n, vi(n, 0)), vis;
    queue<int> eq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 9) {
                si = i;
                sj = j;
                ar[i][j] = 0;
            }
        }
    }
    while (true) {
        sp = 400, spi = -1, spj = -1;
        vi eat;
        vis = vector<vi>(n, vi(n, 400));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ar[i][j] != 0 && ar[i][j] < ss) eat.push_back(i * 100 + j);
        vis[si][sj] = 0;
        eq.push(si * 100 + sj);
        while (!eq.empty()) {
            int eci = eq.front() / 100, ecj = eq.front() % 100;
            eq.pop();
            for (int i = 0; i < 4; i++) {
                int eni = eci + di[i], enj = ecj + dj[i];
                if (eni > -1 && eni < n && enj > -1 && enj < n && vis[eni][enj] > vis[eci][ecj] + 1 && ar[eni][enj] <= ss) {
                    vis[eni][enj] = vis[eci][ecj] + 1;
                    eq.push(eni * 100 + enj);
                }
            }
        }
        for (int i = 0; i < eat.size(); i++) {
            int ei = eat[i] / 100, ej = eat[i] % 100;
            if (vis[ei][ej] < sp) {
                sp = vis[ei][ej];
                spi = ei;
                spj = ej;
            }
        }
        if (spi != -1) {
            ans += sp;
            seat++;
            if (seat == ss) {
                ss++;
                seat = 0;
            }
            ar[spi][spj] = 0;
            si = spi;
            sj = spj;
        } else
            break;
    }
    cout << ans;
    return 0;
}