#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> t;

int diameter;
vector<int> c;

vector<int> bfs(int s) {
    vector<int> d(t.size(), -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : t[v]) {
            if (d[w] == -1) {
                d[w] = d[v] + 1;
                q.push(w);
            }
        }
    }
    return d;
}

void center() {
    int n = t.size();
    vector<int> d1 = bfs(0);
    int a = max_element(d1.begin(), d1.end()) - d1.begin();
    vector<int> d2 = bfs(a);
    int b = max_element(d2.begin(), d2.end()) - d2.begin();
    vector<int> d3 = bfs(b);
    diameter = d3[max_element(d3.begin(), d3.end()) - d3.begin()];
    for (int i = 0; i < n; i++) {
        if ((d2[i] + d3[i] == diameter) && ((d2[i] == (diameter + 1) / 2) || (d3[i] == (diameter + 1) / 2)))
            c.push_back(i);
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        t = vector<vector<int>>(n);
        c = vector<int>();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            t[u].push_back(v), t[v].push_back(u);
        }
        center();
        vector<pair<int, int>> ans;
        if (c.size() == 2) {
            for (int i = 1; i <= (diameter + 1) / 2; i += 2) {
                ans.emplace_back(c[0] + 1, i);
                ans.emplace_back(c[1] + 1, i);
            }
        } else {
            for (int i = 0; i <= diameter / 2; ++i) {
                ans.emplace_back(c[0] + 1, i);
            }
        }
        cout << ans.size() << "\n";
        for (auto a : ans) {
            cout << a.first << " " << a.second << "\n";
        }
    }
}