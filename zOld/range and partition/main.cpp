#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        vector<int> a(n), o(n+1);
        for (int i = 0; i < n; ++i) cin>>a[i], o[a[i]]++;
        for (int i = 1; i < n+1; ++i) o[i] += o[i-1];
        int mn = INT_MAX, x = -1, y = -1;
        for (int i = 1; i <= n; ++i) {
            int l = 0, r = i+1;
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if((o[i] - (mid ? o[mid-1] : 0)) - (o[n] - o[i]) - ((mid ? o[mid-1] : 0) - o[0]) >= k) l = mid;
                else r = mid;
            }
            if(l > 0 && i - l < mn) mn = i - l, x = l, y = i;
        }
        cout << x << " " << y << "\n";
        int l = 0, cnt = 0, cur = 1;
        for (int i = 0; i < n; ++i) {
            if(a[i] >= x && a[i] <= y) cnt++;
            else cnt--;
            if(cnt == cur) {
                if(cur == k) break;
                cout << l + 1 << " " << i + 1 << "\n";
                cur++;
                l = i + 1;
            }
        }
        cout << l + 1 << " " << n << "\n";
    }
}
