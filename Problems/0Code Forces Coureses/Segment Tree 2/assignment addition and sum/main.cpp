#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
struct n { int a; ll p, s; };
vector<n> t((1 << 18) - 1, {-1, 0, 0});

void p(int n, int l, int r) {
    if(2*n + 1 > t.size() - 1) return;
    int mid = (l + r) / 2;

    if(t[n].a != -1) {
        t[2*n+1].a = t[n].a;
        t[2*n+1].p = t[n].p;
        t[2*n+1].s = t[n].a * (mid - l + 1);

        t[2*n+2].a = t[n].a;
        t[2*n+2].p = t[n].p;
        t[2*n+2].s = t[n].a * (r - l);

        t[n].a = -1;
        t[n].p = 0;
    } else {
        t[2*n+1].p += t[n].p;
        t[2*n+1].s += (mid - l + 1) * t[n].p;

        t[2*n+2].p += t[n].p;
        t[2*n+2].s += (r - mid) * t[n].p;

        t[n].p = 0;
    }
}

void assign(int l, int r, int v, int lx = 0, int rx = t.size() / 2, int n = 0) {
    p(n, lx, rx);
    if(rx < l || lx > r) return;
    if(lx >= l && rx <= r) {
        t[n].a = v;
        t[n].p = 0;
        t[n].s = v * (rx - lx + 1);
        return;
    }
    int mid = (lx + rx) / 2;
    assign(l, r, v, lx, mid, 2*n+1);
    assign(l, r, v, mid+1, rx, 2*n+2);
    t[n].s = t[2*n+1].s + t[2*n+2].s + t[n].p * (rx - lx + 1);
}

void add(int l, int r, int v, int lx = 0, int rx = t.size() / 2, int n = 0) {
    p(n, lx, rx);
    if(rx < l || lx > r) return;
    if(lx >= l && rx <= r) {
        t[n].p += v;
        t[n].s += v * (rx - lx + 1);
        return;
    }
    int mid = (lx + rx) / 2;
    add(l, r, v, lx, mid, 2*n+1);
    add(l, r, v, mid+1, rx, 2*n+2);
    t[n].s = t[2*n+1].s + t[2*n+2].s + t[n].p * (rx - lx + 1);
}

ll find(int l, int r, int lx = 0, int rx = t.size() / 2, int n = 0) {
    p(n, lx, rx);
    if(rx < l || lx > r) return 0;
    if(lx >= l && rx <= r) return t[n].s;

    int mid = (lx + rx) / 2;
    return find(l, r, lx, mid, 2*n+1) + find(l, r, mid+1, rx, 2*n+2);
}

int main() {
    int n, m; cin>>n>>m;
    while(m--) {
        int op; cin>>op;
        if(op == 1) {
            int l, r, v; cin>>l>>r>>v, r--;
            assign(l, r, v);
        } else if(op == 2) {
            int l, r, v; cin>>l>>r>>v; r--;
            add(l, r, v);
        } else {
            int l, r; cin>>l>>r; r--;
            cout << find(l, r) << "\n";
        }
    }
}
