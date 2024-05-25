#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> t((1 << 18) - 1);

void p(int n) {
    if(n > t.size() / 2) return;
    t[2*n+1].second += t[n].second, t[2*n+1].first += t[n].second;
    t[2*n+2].second += t[n].second, t[2*n+2].first += t[n].second;
    t[n].second = 0;
}

int get(int l, int x, int n = 0, int lx = 0, int rx = t.size() / 2) {
    p(n);
    if(rx < l || t[n].first < x) return -1;
    if(lx == rx) return lx;

    int mid = (lx + rx) / 2;

    int r = get(l, x, 2*n+1, lx, mid);
    if(r != -1) return r;
    else return get(l, x, 2*n+2, mid+1, rx);
}

void modify(int l, int r, int v, int n = 0, int lx = 0, int rx = t.size() / 2) {
    p(n);
    if(lx >= l && rx <= r) {
        t[n].first += v, t[n].second += v;
        return;
    }
    if(lx > r || rx < l) return;

    int mid = (lx + rx) / 2;
    modify(l, r, v, 2*n+1, lx, mid);
    modify(l, r, v, 2*n+2, mid+1, rx);
    t[n].first = max(t[2*n+1].first, t[2*n+2].first);
}

int main() {
    int n, m; cin>>n>>m;
    while(m--) {
        int p; cin>>p;
        if(p == 1) {
            int l, r, v; cin>>l>>r>>v; r--;
            modify(l, r, v);
        } else {
            int x, l; cin>>x>>l;
            cout << get(l, x) << "\n";
        }
    }
}
