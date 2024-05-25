#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n,m; cin>>n>>m;
    unsigned long long lo = 1, hi = 1ULL << (n-1), l = 0, r = n-1;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        unsigned long long mid = (lo+hi)/2;
        if(m > mid) ans[r] = i+1, r--, lo = mid;
        else ans[l] = i+1, l++, hi = mid;
    }
    for(int c : ans) cout << c << " ";
}
