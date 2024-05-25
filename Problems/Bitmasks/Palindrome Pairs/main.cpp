#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, ans = 0;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int k = 0, p = 0;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        for (int j = 0; j < 26; ++j) if (cnt[j] % 2) k += (1 << j);
        ans += a[k];
        while (p < 27) {
            ans += a[k ^ (1 << p)];
            p++;
        }
        a[k]++;
    }
    cout << ans;
}
