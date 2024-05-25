#include <bits/stdc++.h>

using namespace std;

vector<set<int>> g;
vector<int> ans;

void kahn_topological_sort() {
    ans.clear();
    vector<int> deg = vector<int>(26, 0);
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        for (int u: g[i]) deg[u]++;
    }
    for (int i = 0; i < 26; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v: g[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    g = vector<set<int>>(26);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < min(s[i].size(), s[j].size()); ++k) {
                if (s[i][k] != s[j][k]) {
                    g[s[i][k] - 'a'].insert(s[j][k] - 'a');
                    break;
                }
                if (s[i].size() > s[j].size() && k == s[j].size() - 1) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
        }
    }
    kahn_topological_sort();
    if (ans.size() != 26) cout << "Impossible\n";
    else for (int an : ans) {
        cout << (char) (an + 'a');
    }
}
