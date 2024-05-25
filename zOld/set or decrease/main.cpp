#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        ll n, k, sum=0, ans; cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i], sum+=a[i];
        sort(a.begin(), a.end());
        ans = max(0ll, sum - k);
        for (int i = 0; i < n; ++i) {
            if(i) sum -= a[n-i];
            ll l = -1e10, r = a[0] + 1;
            while(l + 1 < r) {
                ll mid = l + (r - l) / 2;
                if(sum + i*mid - abs(a[0] - mid) <= k) l = mid;
                else r = mid;
            }
            ans = min(ans, i + max(0ll, a[0] - l));
        }
        cout << ans << "\n";
    }
}
