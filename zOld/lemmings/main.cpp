#include <bits/stdc++.h>
using namespace std;
int n,k,h;
vector<pair<pair<int, double>, int>> p;
vector<int> ans, ht;
bool f(double x) {
    ans = vector<int> ();
    auto c = p;
    for (int i = 0; i < c.size(); ++i) c[i].first.second *= x;
    int i1 = 0, cnt = 0;
    for (int i = 0; i < k; ++i, ++i1) {
        while(i1 < c.size() && c[i1].first.second < ht[i]) i1++;
        if(i1 < c.size()) cnt++, ans.push_back(c[i1].second);
    }
    return cnt == k;
}
int main() {
    cin>>n>>k>>h;
    p.resize(n);
    ht.resize(k);
    for (int i = 0; i < k; ++i) ht[i] = (i+1) * h;
    for (int i = 0; i < n; ++i) cin>>p[i].first.first;
    for (int i = 0; i < n; ++i) cin>>p[i].first.second, p[i].second = i;
    sort(p.begin(), p.end());
    double l = 0, r = 1e9;
    for (int i = 0; i < 100; ++i) {
        double mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    f(r);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << " ";
}
