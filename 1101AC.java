import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]), jok=-1, moves=0;
        int[] ccnt = new int[n], ckind=new int[n], inuse=new int[m];
        int[][] cinb = new int[n][m];
        for(int i=0;i<m;i++) inuse[i]=0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c=0, ck=0;
            for (int j = 0; j < m; j++) {
                cinb[i][j] = Integer.parseInt(st.nextToken());
                if(cinb[i][j]!=0){
                    c++;
                    ck=j;
                }
            }
            ccnt[i] = c;
            if(c==1) ckind[i]=ck;
            else ckind[i]=-1;
        }
        for (int i = 0; i < n; i++) {
            if (ccnt[i] == 0) continue;
            if (ccnt[i] == 1 && inuse[ckind[i]] == 0) {
                inuse[ckind[i]] = 1;
            } else if (jok == -1) {
                jok = i;
            } else {
                moves++;
            }
        }
        System.out.println(moves);
    }
}