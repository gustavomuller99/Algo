#include <bits/stdc++.h>
using namespace std;
map<int, int> t1, t2;
vector<int> f;
int n, k = 0;

/* stack... */

void add1(int i, int x) {
    while(i < f.size()) {
        f[i] = max(f[i], x);
        i = i | (i + 1);
    }
}
int get1(int i) {
    int r = -1;
    while(i >= 0) {
        r = max(f[i], r);
        i = (i & (i + 1)) - 1;
    }
    return r;
}
void add2(int i, int x) {
    while(i < f.size()) {
        f[i] = min(f[i], x);
        i = i | (i + 1);
    }
}
int get2(int i) {
    int r = INT_MAX;
    while(i >= 0) {
        r = min(f[i], r);
        i = (i & (i + 1)) - 1;
    }
    return r == INT_MAX ? n : r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    vector<int> a(n), b(n), dist(1e6);
    for (int i = 0; i < n; ++i) cin>>a[i], b[i] = a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if(i && a[i] != a[i-1]) k++;
        t1[a[i]] = k, t2[k] = a[i];
    }
    for (int i = 0; i < n; ++i) b[i] = t1[b[i]];

    f = vector<int> (1e6, -1);
    for (int i = 0; i < n; ++i)
        add1(b[i], i), a[i] = i - get1(b[i]-1);

    f = vector<int> (1e6, INT_MAX);
    for (int i = n-1; i >= 0; --i)
        add2(b[i], i), a[i] += get2(b[i]-1) - i - (a[i] != 0);

    for (int i = 0; i < n; ++i) {
        dist[b[i]] = max(dist[b[i]], a[i]);
    }

    int pos = 1e6-1;
    for (int i = 1; i <= n; ++i) {
        while(dist[pos] < i) pos--;
        cout << t2[pos] << " ";
    }
}
