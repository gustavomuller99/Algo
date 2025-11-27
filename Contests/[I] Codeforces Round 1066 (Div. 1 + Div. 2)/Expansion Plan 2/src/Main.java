import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int x = Math.abs(sc.nextInt());
            int y = Math.abs(sc.nextInt());

            String s = sc.next();
            int count = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '4') {
                    count++;
                }
            }

            if (x > n || y > n || (x + y >= 2 * n - count + 1)) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}
