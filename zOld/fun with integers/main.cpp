#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> d(100001);
int n;

ll dfs(int x, int f = -1) {
    d[x] = 1;
    ll r = 0;
    for (int i = 2*x; i <= n; i+=x) {
        if(i == f) continue;
        if(d[i] != 2) r += 4*(i/x);
        if(d[i] == 0) r += dfs(i, x);
    }
    for (int i = 2; i*i <= x; ++i) {
        if(x % i == 0) {
            if(i != f) {
                if(d[i] != 2) r += 4*(x/i);
                if(d[i] == 0) r += dfs(i, x);
            }
            if(i != x/i && x/i != f) {
                if(d[x/i] != 2) r += 4*(x/(x/i));
                if(d[x/i] == 0) r += dfs((x/i), x);
            }
        }
    }
    d[x] = 2;
    return r;
}

int main() {
    cin>>n;
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if(d[i] == 0) ans = max(ans, dfs(i));
    }
    cout << ans;
}
