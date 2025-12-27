import java.util.*;

public class B_Make_Almost_Equal_With_Mod {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            long[] arr = new long[n];
            for(int i=0;i<n;i++) arr[i] = sc.nextLong();
            boolean isEven = false, isOdd = false;
            for(int i=0;i<n;i++){
                if(isEven && isOdd) break;
                if((arr[i] & 1) == 1) isOdd = true;
                else isEven = true;
            }
            if(isEven && isOdd) System.out.println(2);
            else{
                long k = 2;
                while(k <= 1e18 && k > 0){
                    long rem1 = -1, rem2 = -1;
                    boolean found = true;
                    for(int i=0;i<n;i++){
                        if(rem1 == -1) rem1 = arr[i] % k;
                        else if(rem1 == (arr[i] % k)) continue;
                        else if(rem2 == -1) rem2 = arr[i] % k;
                        else if(rem2 == (arr[i] % k)) continue;
                        else{
                            found = false;
                            break;
                        }
                    }
                    if(found && rem1 != -1 && rem2 != -1){
                        System.out.println(k);
                        break;
                    }
                    k <<= 1;
                }
            }
        }
        sc.close();
    }
}