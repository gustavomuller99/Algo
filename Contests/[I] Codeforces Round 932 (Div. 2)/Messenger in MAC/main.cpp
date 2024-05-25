#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1935/problem/C

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second >> a[i].first;
        }
        std::sort(a.begin(), a.end());
        int maxv = 0;
        for (int i = 0; i < n; ++i) {
            priority_queue<int> m;
            m.push(a[i].second);
            int cur = 0;
            for (int j = i; j < n; ++j) {
                if (i != j) m.push(a[j].second);
                cur += a[j].second;
                while(cur + a[j].first - a[i].first > l && !m.empty()) cur -= m.top(), m.pop();
                if (cur + a[j].first - a[i].first <= l) maxv = max(maxv, (int) m.size());
            }
        }
        cout << maxv << "\n";
    }
}
