import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class CJ {
    public static void main(String[] args) {
        FastScanner n = new FastScanner();
        int count = n.nextInt(),k = 1;
        ArrayList<Integer> result = new ArrayList<Integer>();
        while(count>0){
            int x= n.nextInt();
            int y = n.nextInt();
            String str = n.next();
            StringBuilder s = new StringBuilder(str);
            int t = notNull(s.toString());
            if(t!=-1) {
                for (int i=t; i < s.length(); i++) {
                    if (s.charAt(i) == '?') {
                        s.setCharAt(i, 'C');
                        int val1 = getCount(s.toString(), "CJ");
                        int val2 = getCount(s.toString(), "JC");
                        s.setCharAt(i, 'J');
                        int val3 = getCount(s.toString(), "CJ");
                        int val4 = getCount(s.toString(), "JC");
                        if ((val3 * x) + (val4 * y) > (val1 * x) + (y * val2)) s.setCharAt(i, 'C');
                    }
                }
                for(int i = t;i>=0;i--){
                    if (s.charAt(i) == '?') {
                        s.setCharAt(i, 'C');
                        int val1 = getCount(s.toString(), "CJ");
                        int val2 = getCount(s.toString(), "JC");
                        s.setCharAt(i, 'J');
                        int val3 = getCount(s.toString(), "CJ");
                        int val4 = getCount(s.toString(), "JC");
                        if ((val3 * x) + (val4 * y) > (val1 * x) + (y * val2)) s.setCharAt(i, 'C');
                    }
                }


                //System.out.print(s);
                int val_CJ = getCount(s.toString(), "CJ");
                int val_JC = getCount(s.toString(), "JC");
                result.add((val_CJ * x) + (val_JC * y));
            }
            else result.add(0);
            count--;
        }
        for(Integer i: result){
            System.out.print("Case #"+k+": "+i+"\n");
            k++;
        }
    }
    public static int notNull(String str){
        for(int  i = 0; i < str.length();i++){
            if(str.charAt(i)!='?') return i;
        }
        return -1;
    }
    public static int getCount(String str, String findStr){
        int lastIndex = 0;
        int count = 0;

        while(lastIndex != -1){

            lastIndex = str.indexOf(findStr,lastIndex);

            if(lastIndex != -1){
                count ++;
                lastIndex += findStr.length();
            }
        }
        return count;
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}