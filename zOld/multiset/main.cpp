#include <bits/stdc++.h>
using namespace std;

vector<int> f;

void add(int i, int x) {
    while(i < f.size()) {
        f[i] += x;
        i = i | (i + 1);
    }
}

int get(int i) {
    int r = 0;
    while(i >= 0) {
        r += f[i];
        i = (i & (i + 1)) - 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin>>n>>q;
    f.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin>>x; add(x, 1);
    }
    for (int i = 0; i < q; ++i) {
        int x; cin>>x;
        if(x < 0) {
            x = -x;
            int l = 0, r = n + 1;
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if(get(mid) >= x) r = mid;
                else l = mid;
            }
            add(r, -1);
        } else add(x, 1);
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i) if(get(i) - get(i-1) > 0) ans = i;
    cout << ans;
}
