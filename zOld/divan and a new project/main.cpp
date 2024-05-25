#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool compare(const pair<ll, ll> & a, const pair<ll, ll> & b) {
    return a.second < b.second;
}

int main() {
    int t; cin>>t; while(t--) {
        int n; ll ans=0; cin>>n;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i].first, a[i].second = i;
        sort(a.begin(), a.end());
        for (long long i = a.size()-1; i >= 0; i -= 2) {
            ans += (a.size() - i + 1) / 2 * a[i].first * 2;
            a[i].first = a.size() / 2 + 1 + (a.size() - i + 1) / 2;
            if (i - 1 >= 0) {
                ans += (a.size() - i + 1) / 2 * a[i-1].first * 2;
                a[i-1].first = a.size() / 2 + 1 - (a.size() - i + 1) / 2;
            }
        }
        sort(a.begin(), a.end(), compare);
        cout << ans << "\n" << a.size() / 2 + 1 << " ";
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << " ";
        } cout << "\n";
    }
}
