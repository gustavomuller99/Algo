#include <bits/stdc++.h>
using namespace std;
vector<int> l, r, v;

int gl(int u) { return v[u] ? l[u] = gl(l[u]) : u; }

int gr(int u) { return v[u] ? r[u] = gr(r[u]) : u; }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, p; cin>>n>>m>>p;
    string s, op; cin>>s>>op;
    stack<int> q;
    vector<int> pr(n+2); r.resize(n+2), v.resize(n+2), l.resize(n+2);
    for (int i = 1; i <= n; ++i) r[i] = i+1, l[i] = i-1;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') q.push(i+1);
        else {
            int k = q.top(); q.pop();
            pr[k] = i+1, pr[i+1] = k;
        }
    }
    for (int i = 0; i < m; ++i) {
        if(op[i] == 'R') p = gr(p+1);
        if(op[i] == 'L') p = gl(p-1);
        if(op[i] == 'D') {
            int k = pr[p], c = p;
            if(k > c) swap(k, c);
            l[gr(c+1)] = gl(k-1), r[gl(k-1)] = gr(c+1);
            for (int j = k; j <= c; j=gr(j)) v[j] = 1;
            p = gr(p);
            if(p > n) p = gl(p-1);
            if(p < 1) p = gr(p+1);
        }
    }
    for (int i = 0; i < n; ++i) if(v[i+1]==0) cout << s[i];
}
