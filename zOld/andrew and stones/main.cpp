#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        unsigned long long n, s = 0; cin>>n;
        vector<int> a(n);
        bool k = false;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(i && i < n-1)
                s += (a[i] / 2) + (a[i] % 2),
                k |= a[i] > 1;
        }

        if(k && !(n == 3 && a[1] % 2)) cout << s << "\n";
        else cout << "-1\n";
    }
}
