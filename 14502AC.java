import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

 class Main1 {

    public static class Location {
        private final int x;
        private final int y;

        public Location(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static final List<Location> virusList = new ArrayList<>();
    private static final int[] dx = {1, -1, 0, 0};  // up, down
    private static final int[] dy = {0, 0, 1, -1};  // left, right

    private static int n, m;
    private static int[][] map, copyMap;
    private static int result = 0;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        copyMap = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 2) {
                    virusList.add(new Location(i, j));
                }
            }
        }
        setWall(0, 0);
        System.out.println(result);
    }

    private static void setWall(int start, int depth) {
        if (depth == 3) {
            for (int i = 0; i < n; i++) {
                if (m >= 0) System.arraycopy(map[i], 0, copyMap[i], 0, m);
            }
            for (Location location : virusList) {
                spreadVirus(location.x, location.y);
            }

            int cnt=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(copyMap[i][j]==0) cnt++;
                }
            }
            result = Math.max(result, cnt);
            return;
        }
        for (int i = start; i < n * m; i++) {
            int x = i / m;  // row
            int y = i % m;  // column

            if (map[x][y] == 0) {
                map[x][y] = 1;
                setWall(i + 1, depth + 1);
                map[x][y] = 0;
            }
        }
    }

    private static void spreadVirus(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (copyMap[nx][ny] == 0) {
                    copyMap[nx][ny] = 2;
                    spreadVirus(nx, ny);
                }
            }
        }
    }
}
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, plen, wlen, cnt;
    static int[] di, dj;
    static int[][] ar, vis;
    static ArrayList<Integer> pos;
    static ArrayList<ArrayList<Integer>> poswall;
    static Queue<Integer> virus;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        di = new int[]{-1, 0, 1, 0};
        dj = new int[]{0, 1, 0, -1};
        cnt = 0;
        ar = new int[n][m];
        vis = new int[n][m];
        pos = new ArrayList<>();
        poswall = new ArrayList<>();
        virus=new LinkedList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            Arrays.fill(vis[i], 0);
            for (int j = 0; j < m; j++) {
                ar[i][j] = Integer.parseInt(st.nextToken());
                if (ar[i][j] == 0) pos.add(i * m + j);
                else if (ar[i][j] == 2) {
                    virus.add(i * m + j);
                    vis[i][j] = 1;
                }
            }
        }
        plen = pos.size();
        for (int i = 0; i < plen; i++) {
            for (int j = i + 1; j < plen; j++) {
                for (int k = j + 1; k < plen; k++) {
                    ArrayList<Integer> tmp = new ArrayList<>();
                    tmp.add(pos.get(i));
                    tmp.add(pos.get(j));
                    tmp.add(pos.get(k));
                    poswall.add(tmp);
                }
            }
        }
        wlen = poswall.size();
        for (int i = 0; i < wlen; i++) {
            int tcnt = 0;
//            ArrayList<ArrayList<Integer>> tar = new ArrayList(
//                    Arrays.stream(ar)
//                            .map(r -> IntStream.of(r).boxed().collect(Collectors.toList()))
//                            .collect(Collectors.toList()));
//            ArrayList<ArrayList<Integer>> tvis = new ArrayList(
//                    Arrays.stream(ar)
//                            .map(r -> IntStream.of(r).boxed().collect(Collectors.toList()))
//                            .collect(Collectors.toList()));
            int[][] tar=new int[n][m], tvis=new int[n][m];
            for (int ii = 0; ii < n; ii++) {
                System.arraycopy(ar[ii], 0, tar[ii], 0, m);
                System.arraycopy(vis[ii], 0, tvis[ii], 0, m);
            }
            for (int j = 0; j < 3; j++)
                tar[poswall.get(i).get(j)/m][poswall.get(i).get(j)%m]=1;
//                tar.get(poswall.get(i).get(j) / m).set(poswall.get(i).get(j) % m, 1);
            Queue<Integer> q = new LinkedList<>(virus);
            while (!q.isEmpty()) {
                int curi = q.peek() / m, curj = q.peek() % m;
                q.poll();
                for (int k = 0; k < 4; k++) {
                    int ni = curi + di[k], nj = curj + dj[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;
                    if (tar[ni][nj]!=0 || tvis[ni][nj]==1)//tar.get(ni).get(nj) != 0 || tvis.get(ni).get(nj) == 1)
                        continue;
                    tar[ni][nj]=2;
                    tvis[ni][nj]=1;
//                    tar.get(ni).set(nj, 2);
//                    tvis.get(ni).set(nj, 1);
                    q.add(ni * m + nj);
                }
            }
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
//                    if (tar.get(k).get(l) == 0) tcnt++;
                    if(tar[k][l]==0) tcnt++;
                }
            }
            cnt = (cnt < tcnt) ? tcnt : cnt;
        }
        System.out.println(cnt);
    }
}