import java.util.*;

public class Main {

    public static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n, k, q;
            n = sc.nextInt();
            k = sc.nextInt();
            q = sc.nextInt();

            ArrayList<Integer> ans = new ArrayList<>(n);
            ArrayList<Boolean> mex = new ArrayList<>(n);
            ArrayList<Boolean> min = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                ans.add(0);
                mex.add(false);
                min.add(false);
            }

            for (int i = 0; i < q; i++) {
                int c, l, r;
                c = sc.nextInt();
                l = sc.nextInt();
                r = sc.nextInt();
                l--;
                r--;

                for (int j = l; j <= r; j++) {
                    if (c == 1)
                        min.set(j, true);
                    else
                        mex.set(j, true);
                }
            }

            for (int i = 0; i < n; i++) {
                if (min.get(i) && mex.get(i)) {
                    ans.set(i, k + 1);
                } else if (min.get(i)) {
                    ans.set(i, k);
                } else if (mex.get(i)) {
                    ans.set(i, i % k);
                } else {
                    ans.set(i, k + 1);
                }
            }

            for (int i = 0; i < n; i++) {
                System.out.printf("%d ", ans.get(i));
            }
            System.out.println();
        }
    }
}
