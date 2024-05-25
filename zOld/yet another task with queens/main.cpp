#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<pair<int, int>> p(m);
    vector<int> c(n+1), r(n+1), dr(2*n+1), dl(2*n+1), am(m), ans(9);
    for (int i = 0; i < m; ++i) cin>>p[i].first>>p[i].second;
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < m; ++i) {
        int rw = p[i].first, cl = p[i].second;
        am[i] += (c[cl] > 0) + (r[rw] > 0) + (dr[n-rw+cl] > 0) + (dl[2*n-rw-cl] > 0);
        c[cl]++, r[rw]++, dr[n-rw+cl]++, dl[2*n-rw-cl]++;
    }
    c = vector<int> (n+1), r = vector<int> (n+1), dr = vector<int> (2*n+1), dl = vector<int> (2*n+1);
    for (int i = m-1; i >= 0; --i) {
        int rw = p[i].first, cl = p[i].second;
        am[i] += (c[cl] > 0) + (r[rw] > 0) + (dr[n-rw+cl] > 0) + (dl[2*n-rw-cl] > 0);
        c[cl]++, r[rw]++, dr[n-rw+cl]++, dl[2*n-rw-cl]++;
    }
    for (int i = 0; i < m; ++i) {
        ans[am[i]]++;
    }
    for (int i = 0; i < 9; ++i) {
        cout << ans[i] << " ";
    }
}
