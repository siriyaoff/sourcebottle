import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), q = Integer.parseInt(input[1]), c = Integer.parseInt(input[2]), curbw=0, curfw=0, curp=-1;
        int[] cap = new int[n];
        Stack<Integer> bw = new Stack<>(), fw=new Stack<>();
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            cap[i] = Integer.parseInt(input[i]);
        }
        for (int i = 0; i < q; i++) {
            input = br.readLine().split(" ");
            char cmd=input[0].charAt(0);
            if(cmd=='A'){
                int pt;
                pt = Integer.parseInt(input[1]);
                fw.clear();
                curfw=0;
                if(curp!=-1){
                    bw.push(curp);
                    curbw+=cap[curp];
                }
                curp=pt-1;
                while(curbw+cap[curp]>c){
                    curbw-=cap[bw.get(0)];
                    bw.remove(0);
                }
            }
            else if(cmd=='B'){
                if(bw.empty()) continue;
                fw.push(curp);
                curfw+=cap[curp];
                curp=bw.pop();
                curbw-=cap[curp];
            }
            else if(cmd=='C'){
                for (int j = bw.size() - 1; j > 0; j--) {
                    if(bw.get(j).intValue()==bw.get(j-1).intValue()){
                        curbw-=cap[bw.get(j-1)];
                        bw.remove(j-1);
                    }
                }
            }
            else if(cmd=='F'){
                if(fw.empty()) continue;
                bw.push(curp);
                curbw+=cap[curp];
                curp=fw.pop();
                curfw-=cap[curp];
            }
        }
        System.out.println(curp + 1);
        if(bw.empty()) System.out.println(-1);
        else {
            while (!bw.empty()) {
                System.out.print(""+(bw.pop()+1)+' ');
            }
            System.out.println("");
        }
        if(fw.empty()) System.out.println(-1);
        else{
            while(!fw.empty()){
                System.out.print(""+(fw.pop()+1)+' ');
            }
        }
    }
}