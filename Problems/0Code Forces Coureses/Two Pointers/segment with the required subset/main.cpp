#include <bits/stdc++.h>
using namespace std;

stack<bitset<1001>> b, f;
int n, s;
vector<int> a;

bitset<1001> join(int x, bitset<1001> y) {
    bitset<1001> r;
    for (int i = 0; i <= s; ++i) if(y[i]) r[i] = true, r[i+x] = true;
    return r;
}

void add(int x) {
    bitset<1001> add;
    if(!f.empty()) add = join(x, f.top());
    add[x] = true;
    f.push(add);
}

void remove(int l, int r) {
    if(!b.empty()) b.pop();
    else {
        while(!f.empty()) f.pop();
        for (int i = r; i > l; --i) {
            bitset<1001> add;
            if(!b.empty()) add = join(a[i], b.top());
            add[a[i]] = true;
            b.push(add);
        }
    }
}

bool check() {
    if(!b.empty()) if(b.top()[s]) return true;
    if(!f.empty()) if(f.top()[s]) return true;
    if(!b.empty() && !f.empty()) for (int i = 0; i <= s; ++i) {
        if((b.top()[i] && f.top()[s-i]) || (b.top()[s-i] && f.top()[i])) return true;
    }
    return false;
}

int main() {
    cin>>n>>s;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int r = 0, l = -1, ans = INT_MAX;
    while(l < n) {
        while(r < n && !check()) add(a[r]), r++;
        if(check()) ans = min(ans, r-l);
        if(l >= 0) remove(l, r-1);
        l++;
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
