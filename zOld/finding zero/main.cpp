#include <bits/stdc++.h>
using namespace std;

pair<int, int> check(const vector<int>& a) {
    pair<int, int> r = {-1, -1};
    vector<pair<int, vector<int>>> v;
    for (int i = 0; i < 2; ++i) {
        for (int j = i+1; j < 3; ++j) {
            for (int k = j+1; k < 4; ++k) {
                cout << "? " << a[i] + 1 << " " << a[j] + 1 << " " << a[k] + 1 << "\n";
                cout.flush();
                int x; cin>>x;
                vector<int> y = {a[i], a[j], a[k]};
                v.emplace_back(x, y);
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(v[2].second[i] == v[3].second[j]) {
                if(r.first == -1) r.first = v[2].second[i];
                else r.second = v[2].second[i];
            }
        }
    }
    return r;
}

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        pair<int, int> ans = {0, 1};
        for (int i = 2; i < n; i += 2) {
            while(i == ans.first || i == ans.second) i++;
            int x = i+1;
            while(x > n-1 || x == ans.first || x == ans.second || x == i) x--;
            ans = check({ans.first, ans.second, i, x});
        }
        cout << "! " << ans.first + 1 << " " << ans.second + 1 << "\n";
        cout.flush();
    }
}
