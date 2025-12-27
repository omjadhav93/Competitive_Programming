import java.util.*;

public class D_Plus_Minus_Permutation {

    public static int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    public static long lcm(int a, int b){
        if(a == 0 || b == 0) return 0;
        return (1l * a * b) / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            long lc = lcm(x, y);
            long c = n / lc;
            long a = n / x - c;
            long b = n / y - c;
            a = n - a + 1;
            long s = (((n+a) * (n-a+1)) / 2) - ((b * (b + 1)) / 2);
            System.out.println(s);
        }
        sc.close();
    }
}