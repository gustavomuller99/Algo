#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> p;
vector<string> g(3);
bool test(int r, int c, int time) {
    for(auto x : p) {
        if(r == x.first &&
            c >= x.second.first - 2*time &&
            c <= x.second.second - 2*time) return false;
    }
    return true;
}

bool dfs(int r, int c, int time = 0) {
    if(g[r][c] == '$' || !test(r, c, time)) return false;
    g[r][c] = '$';
    if(c == g[0].size()-1) return true;
    bool rt = false, f = test(r, c+1, time);
    if(r > 0 && f && test(r-1, c+1, time)) rt |= dfs(r-1, c+1, time+1);
    if(r < 2 && f && test(r+1, c+1, time)) rt |= dfs(r+1, c+1, time+1);
    if(f) rt |= dfs(r, c+1, time+1);
    return rt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        p = vector<pair<int, pair<int, int>>> ();
        pair<int, int> pos;
        for (int i = 0; i < 3; ++i) {
            string s; cin>>s;
            g[i] = s;
            int cur = -1, l, r;
            for (int j = 0; j < s.size(); ++j) {
                if(s[j] == 's') pos = {i, j};
                else if(s[j] - 'A' >= 0 && cur == -1) cur = s[j], l = j, r = j;
                if(cur != -1) {
                    while(j < s.size()-1 && s[r] == s[r+1]) r++;
                    p.push_back({i, {l, r}});
                    j = r;
                }
                cur = -1;
            }
        }
        cout << (dfs(pos.first, pos.second) ? "YES\n" : "NO\n");
    }
}
