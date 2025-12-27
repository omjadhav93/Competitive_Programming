import java.util.*;

public class C_Assembly_via_Minimums {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            Integer[] data = new Integer[(n * (n-1)) / 2];
            for(int i = 0; i < (n * (n-1)) / 2; i++){
                data[i] = sc.nextInt();
            }
            
            Arrays.sort(data);

            int x = n-1, i=0;
            while(x > 0){
                System.out.print(data[i] + " ");
                i += x;
                x--;

            }
            System.out.println(data[i-1]);

        }
        sc.close();
    }
}