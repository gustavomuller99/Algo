#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        vector<int> s(2*k+1), p(2*k+1), a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n / 2; ++i) {
            if(max(a[i], a[n-i-1]) + k + 1 <= 2*k) s[max(a[i], a[n-i-1]) + k + 1]--;
            s[min(a[i], a[n-i-1]) + 1]++;
            p[a[i] + a[n-i-1]]++;
        }
        for (int i = 1; i < s.size(); ++i) s[i] += s[i-1];
        int ans = INT_MAX;
        for (int i = 0; i < 2*k+1; ++i) {
            ans = min(ans, s[i] + (n/2 - s[i]) * 2 - p[i]);
        }
        cout << ans << "\n";
    }
}
