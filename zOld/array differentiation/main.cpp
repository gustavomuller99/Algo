#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n,k=1; cin>>n;
        vector<int> a(n);
        bool ans = false;
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) k *= 3;
        for (int i = 1; i < k; ++i) {
            int kp = i, sum = 0;
            for (int j = 0; j < n; ++j) {
                int s = kp % 3;
                if(kp % 3 == 2) s = -1;
                sum += s*a[j];
                kp /= 3;
            }
            if(sum == 0) ans = true;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
