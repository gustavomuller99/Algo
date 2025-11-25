import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int v, t;

        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            v = sc.nextInt();
            t = sc.nextInt();

            System.out.println(2 * v * t);
        }
    }
}
