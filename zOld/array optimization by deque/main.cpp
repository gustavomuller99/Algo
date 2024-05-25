#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, pair<int, int>>> m;
vector<int> s;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int g(int l, int r, int lx, int rx, int i = 0) {
    if(lx >= l && rx <= r) return s[i];
    if(lx > r || rx < l) return 0;
    return g(l, r, lx, (lx+rx)/2, 2*i+1) + g(l, r, (lx+rx)/2+1, rx, 2*i+2);
}

void u(int l) {
    s[l] = 1;
    while(l != 0) {
        l = l/2 - (l%2==0);
        s[l] = s[2*l + 1] + s[2*l + 2];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k = 1; long long ans = 0; cin>>n;
        vector<pair<int,int>> a(n);
        m = map<int, pair<int, pair<int, int>>> ();
        s = vector<int> ();
        for (int i = 0; i < n; ++i) cin>>a[i].first, a[i].second = i;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            int b = i;
            while(i != n-1 && a[i+1].first == a[i].first) i++;
            m[a[i].first] = {b, {b, i}};
        }
        sort(a.begin(), a.end(), compare);
        while(k < n) k *= 2; k *= 2, k--;
        s.resize(k);
        for (int i = 0; i < n; ++i) {
            ans += min(g(k/2, m[a[i].first].second.first - 1 + k/2, k/2, k-1),
                       g(m[a[i].first].second.second + 1 + k/2, k-1, k/2, k-1));
            u(m[a[i].first].first+k/2);
            m[a[i].first].first++;
        }
        cout << ans << "\n";
    }
}
