#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        if(a[i] == 1) {
            int l=INT_MAX, r=INT_MAX;
            for (int j = i-1; j >= 0; --j) {
                if(a[j] == 0) { l = j; break; }
            }
            for (int j = i+1; j < n; ++j) {
                if(a[j] == 0) { r = j; break; }
            }
            if(abs(i-l) <= abs(r-i)) a[l] = i+2, ans += i-l;
            else a[r] = i+3, ans += r-i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(a[i] > 2) cout << a[i]-2 << " ";
        else cout << a[i] << " ";
    } cout << "\n";
    cout << ans;
}
