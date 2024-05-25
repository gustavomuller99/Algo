#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m,v; cin>>n>>m>>v;
    if(m > (n-1)*(n-2)/2 + 1 || m < n-1) cout << -1;
    else {
        int f = (v == 1 ? 2 : 1);
        vector<int> a;
        for (int i = 1; i <= n; ++i) if(i != f) a.push_back(i);
        cout << f << " " << v << "\n"; m--;
        for (int i = 0; i < a.size() && m; ++i) {
            for (int j = i+1; j < a.size() && m; ++j) {
                cout << a[i] << " " << a[j] << "\n";
                m--;
            }
        }
    }
}
