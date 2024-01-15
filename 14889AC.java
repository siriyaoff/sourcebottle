import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.abs;
import static java.lang.Math.min;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, len, min;
    static int[][] ar;

    public static int pow(int x, int p) {
        int r = 1;
        while (p != 0) {
            if ((p & 0x1) == 0x1)
                r *= x;
            x *= x;
            p >>= 1;
        }
        return r;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        min = 9000;
        len = pow(2, n);
        ar = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                ar[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < len; i++) {
            int cnt = 0, ti = i;
            int[] stat = {0, 0}, seq = new int[n];
            for (int j = 0; j < n; j++) {
                cnt += (ti & 0x1);
                seq[j] = (ti & 0x1);
                ti >>= 1;
            }
            if (cnt != n / 2) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                int curt = seq[j];
                for (int k = j + 1; k < n; k++) {
                    if (seq[k] == curt) {
                        stat[curt] += ar[j][k] + ar[k][j];
                    }
                }
            }
            cnt = abs(stat[0] - stat[1]);
            min = min(min, cnt);
        }
        System.out.println(min);
    }
}