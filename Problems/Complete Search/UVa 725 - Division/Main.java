import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n != 0) {
            boolean sol = false;

            // 01234 is the min, <= 98765 / n so that b * n <= 98765
            for (int b = 1234; b <= 98765 / n; b++) {
                int a = b * n;
                int tempa = a;
                int tempb = b;

                int flag = (b < 10000 ? 1 : 0);
                while (tempa != 0) {
                    flag |= (1 << (tempa % 10));
                    tempa /= 10;
                }
                while (tempb != 0) {
                    flag |= (1 << (tempb % 10));
                    tempb /= 10;
                }
                if (flag == (1 << 10) - 1) {
                    sol = true;
                    System.out.println(String.format("%05d", a) + " / " + String.format("%05d", b) + " = " + n);
                }
            }

            if (!sol) {
                System.out.println("There are no solutions for " + n + ".");
            }

            n = sc.nextInt();
            if (n != 0) {
                System.out.println();
            }
        }
    }
}
