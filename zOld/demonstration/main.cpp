#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n,k,ans; cin>>n>>k; ans=n;
    ll b,s=0; cin>>b;
    vector<pair<int, int>> c(n);
    vector<bool> a(n);
    for (int i = 0; i < n; ++i) { cin>>c[i].first, c[i].second=i; }
    c.pop_back();
    sort(c.begin(), c.end(), greater<>());
    for (int i = 0; i < k-1; ++i) {
        s += c[i].first, a[i] = true;
    }
    for (int i = 0; i < c.size(); ++i) {
        if(s + (a[i] ? c[k-1].first : c[i].first) > b) {
            ans = min(ans, c[i].second+1);
        }
    }
    cout << ans;
}
