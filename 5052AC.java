import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine()), n;
        while(t-->0){
            n = Integer.parseInt(br.readLine());
            ArrayList<String> a=new ArrayList<>();
            for(int i=0;i<n;i++) a.add(br.readLine().replaceAll("\\s", ""));
            Comparator<String> mycomp=new Comparator<>() {
                @Override
                public int compare(String o1, String o2) { // positive : o2>o1
                    int e=(o1.length()<o2.length())?o1.length():o2.length();
                    for(int i=0;i<e;i++){
                        if(o1.charAt(i)==o2.charAt(i)) continue;
                        else if(o1.charAt(i)>o2.charAt(i)) return 1;
                        else return -1;
                    }
                    return o1.length()-o2.length();
                }
            };
            Collections.sort(a, mycomp);
            int f=1;
            for(int i=0;i<n-1;i++){
                if(a.get(i+1).indexOf(a.get(i))==0){
                    System.out.println("NO");
                    f=0;
                    break;
                }
            }
            if(f==1) System.out.println("YES");
        }
    }
}