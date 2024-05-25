#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ka = 2 * k, kb = 2 * k;
        vector<int> a_ans, b_ans;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[x]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 2 && kb > 0) b_ans.push_back(i), b_ans.push_back(i), kb -= 2;
            if (a[i] == 2 && ka > 0) a_ans.push_back(i), a_ans.push_back(i), ka -= 2;
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i] == a[i] && ka > 0 && kb > 0) b_ans.push_back(i), a_ans.push_back(i), ka--, kb--;
        }
        for (int x : a_ans) cout << x << " ";
        cout << "\n";
        for (int x : b_ans) cout << x << " ";
        cout << "\n";
    }
}
