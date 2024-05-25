#include <bits/stdc++.h>
using namespace std;

vector<int> f;

int get(int l) {
    int s = 0;
    for(; l >= 0; l = (l & (l + 1)) - 1) {
        s += f[l];
    }
    return s;
}

void upd(int l, int x) {
    for(; l < f.size(); l = l | (l + 1)) {
        f[l] += x;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    long long ans = 0;
    f.resize(n+1);
    vector<int> a(n);
    map<int, int> l, r;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = n-1; i >= 0; --i) {
        r[a[i]]++;
        upd(r[a[i]], 1);
    }
    for (int i = 0; i < n; ++i) {
        upd(r[a[i]], -1);
        r[a[i]]--;
        l[a[i]]++;
        ans += get(l[a[i]] - 1);
    }
    cout << ans;
}
