#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s = 0; cin>>n;
    vector<int> a(n), d(n*2001); d[0] = 1;
    for (int i = 0; i < n; ++i) cin>>a[i], s += a[i];
    for (int i = 0; i < n; ++i)
        for (int j = d.size()-1; j >= a[i]; --j) d[j] = d[j] | d[j-a[i]];
    if(d[s/2] == 0 || s % 2) cout << 0;
    else {
        int l = INT_MAX, p = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            while((a[i] & 1 << k) == 0) k++;
            if(k < l) l = k, p = i+1;
        }
        cout << 1 << "\n" << p;
    }
}
