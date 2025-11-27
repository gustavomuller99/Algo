import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int ans = 0;
            int[] count = new int[n + 1];

            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                count[x]++;
            }

            for (int i = 0; i < n + 1; i++) {
                if (count[i] > 0) {
                    ans += Math.min(count[i], count[i] >= i ? count[i] - i : count[i]);
                }
            }

            System.out.println(ans);
        }
    }
}
