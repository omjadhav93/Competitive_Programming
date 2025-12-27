import java.util.*;

public class B_Vika_and_the_Bridge {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            int[][] diff = new int[k][3];
            for(int i=0;i<n;i++) arr[i] = sc.nextInt();
            for(int i=0;i<n;i++){
                int r = arr[i]-1;
                int d = diff[r][2] > 0 ? i - diff[r][2] : i;
                if(diff[r][1] <= d){
                    diff[r][0] = diff[r][1];
                    diff[r][1] = d;
                }else if(diff[r][0] <= d){
                    diff[r][0] = d;
                }
                diff[r][2] = i + 1;
            }
            int ans = Integer.MAX_VALUE;
            for(int i=0;i<k;i++){
                if(diff[i][2] > 0){
                    int d = n - diff[i][2];
                    if(diff[i][1] <= d){
                        diff[i][0] = diff[i][1];
                        diff[i][1] = d;
                    }else if(diff[i][0] <= d){
                        diff[i][0] = d;
                    }
                    
                    ans = Integer.min(ans, Integer.max(diff[i][0], (diff[i][1] % 2) != 0 ? (diff[i][1] - 1) / 2 : (diff[i][1] / 2)));
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}