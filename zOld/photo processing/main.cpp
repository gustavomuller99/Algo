#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
bool f(int x) {
    vector<int> f(n);
    if(a[k-1] - a[0] <= x) f[k-1] = 1;
    int l = 0;
    for (int i = k; i < n; ++i) {
        while(a[i] - a[l] > x) l++;
        if(l == 0) f[i] = 1;
        else if(l <= i-k+1) f[i] = (f[i-k] - (l > 1 ? f[l-2] : 0)) > 0;
        f[i] += f[i-1];
    }
    return f[n-1] - (n > 1 ? f[n-2] : 0) > 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    sort(a.begin(), a.end());
    int l = -1, r = 1e9+1;
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
