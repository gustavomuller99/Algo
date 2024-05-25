#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, c; cin>>n>>k;
    vector<int> a(n), u(1e6);
    for (int i = 0; i < n; ++i) cin>>a[i];
    long long l = 0, r = 0, ans = 0; u[a[0]] = 1; c = 1;
    if(k) while(l < n) {
        while(r < n-1) {
            r++;
            if(!u[a[r]]) c++;
            if(c > k) {
                r--; c--; break;
            } else u[a[r]]++;
        }
        ans += r - l + 1;
        u[a[l]]--;
        if(!u[a[l]]) c--;
        l++;
    }
    cout << ans;
}
