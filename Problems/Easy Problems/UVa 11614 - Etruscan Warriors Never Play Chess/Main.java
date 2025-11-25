import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            long n = sc.nextLong();

            // s = (i * (i + 1)) / 2
            // s = (i^2 + i) / 2
            // 0 = i^2 + i - 2s
            // == (-1 + sqrt(1 + 8s)) / 2

            System.out.println((long) Math.floor((-1 + Math.sqrt(1 + 8 * n)) / 2));
        }
    }
}
