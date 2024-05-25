#include <bits/stdc++.h>

using namespace std;

int n, tc = 1, p;
vector<vector<int>> g;
vector<int> ans;

void kahn_topological_sort() {
    ans.clear();
    vector<int> deg = vector<int>(n, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        for (int u: g[i]) deg[u]++;
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans.push_back(u);
        for (int v: g[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
}

void solve() {
    map<string, int> m;
    map<int, string> minv;
    g = vector<vector<int>> (n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[s] = i;
        minv[i] = s;
    }
    cin >> p;
    for (int i = 0; i < p; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        g[m[s1]].push_back(m[s2]);
    }
    kahn_topological_sort();
    cout << "Case #" << tc << ": Dilbert should drink beverages in this order: ";
    for (int i = 0; i < ans.size(); ++i) {
        cout << minv[ans[i]];
        cout << (i == ans.size() - 1 ? "." : " ");
    }
    cout << "\n\n";
}

int main() {
    while (cin >> n && n) {
        solve();
        tc++;
    }
}
