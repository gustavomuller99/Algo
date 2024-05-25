#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mex = n;
        vector<int> a(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                mex = i;
                break;
            }
        }
        vector<pair<int, int>> seg;
        set<int> cur;
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mex) cur.insert(a[i]);
            if (cur.size() == mex) {
                seg.emplace_back(l, i);
                l = i + 1;
                cur = set<int>();
            }
        }
        if (seg.size() == 1 || seg.empty()) cout << "-1\n";
        else {
            cout << seg.size() << "\n";
            for (int i = 0; i < seg.size() - 1; ++i) {
                cout << seg[i].first + 1 << " " << seg[i].second + 1 << "\n";
            }
            cout << seg[seg.size() - 1].first + 1 << " " << n << "\n";
        }
    }
}
