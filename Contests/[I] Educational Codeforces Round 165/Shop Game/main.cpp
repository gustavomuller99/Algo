#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> it(n);
        for (int i = 0; i < n; ++i) cin >> it[i].second;
        for (int i = 0; i < n; ++i) cin >> it[i].first;
        sort(it.begin(), it.end(), greater<>());
        ll free = 0, profit = 0;
        multiset<ll> s;
        for (int i = 0; i < k; ++i) free += it[i].second, s.insert(it[i].second);
        for (int i = k; i < n; ++i) profit += max(0, it[i].first - it[i].second);
        ll ans = 0;
        for (int i = k; i < n; ++i) {
            ans = max(ans, profit - free);
            profit -= max(0, it[i].first - it[i].second);
            ll last = (s.empty() ? 0 : *(--s.end()));
            if (it[i].second < last) {
                s.erase(s.find(last));
                s.insert(it[i].second);
                free -= last;
                free += it[i].second;
            }
        }
        cout << max(0ll, ans) << "\n";
    }
}
