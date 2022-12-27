import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long a = Long.parseLong(input[0]), b = Long.parseLong(input[1]), t = 0, m = -1;
        int n = 0, f=0;
        if (a == 0) {
            System.out.println('-');
            return;
        }
        if (b == 1) {
            System.out.println('*');
            return;
        }
        if (a<b-a) {
            a = b - a;
            f = 1;
        }
        while(n<=60){
            t = (long) Math.pow((double) 2, (double) n);
            n++;
            if(b>t) continue;
            else if(b==t) break;
            else if ((t - 1) % b == 0) {
                m = (t-1) / b;
                break;
            }
        }
        if(m==-1){
            System.out.println(-1);
            return;
        }
        t = m * a;
        StringBuilder st = new StringBuilder(Long.toBinaryString(t));
        if(st.length()>60) System.out.println(-1);
        else {
            if (f==1) {
                for (int i = 0; i < st.length(); i++) {
                    st.replace(i, i + 1, Integer.toString('1' - st.charAt(i)).substring(0, 1));
                }
            }
            for (int i = 0; i < st.length(); i++) {
                if (st.charAt(i) == '1') st.replace(i, i + 1, "*");
                else st.replace(i, i + 1, "-");
            }
            System.out.println(st);
        }
    }
}