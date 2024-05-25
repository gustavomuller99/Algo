#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string in; cin>>in;
    stack<pair<int, char>> s;
    stack<pair<int,int>> m;
    vector<pair<int, pair<int,int>>> v;
    for (int i = 0; i < in.size(); ++i) {
        if(in[i] == '[' || in[i] == '(') {
            s.push({i, in[i]});
        } else if(in[i] == ')') {
            if(s.empty()) continue;
            auto c = s.top(); s.pop();
            if(c.second != '(') s = stack<pair<int, char>>();
            else {
                while(!m.empty() && m.top().first > c.first) m.pop();
                m.push({c.first, i});
            }
        } else if(in[i] == ']') {
            if(s.empty()) continue;
            auto c = s.top(); s.pop();
            if(c.second != '[') s = stack<pair<int, char>>();
            else {
                while(!m.empty() && m.top().first > c.first) m.pop();
                m.push({c.first, i});
            }
        }
    }
    while(!m.empty()) {
        int b = 0;
        auto c = m.top(); m.pop();
        for (int i = c.first; i < c.second; ++i) {
            if(in[i] == '[') b++;
        }
        v.push_back({b, c});
    }
    pair<int, pair<int,int>> ans = {0, {0,0}};
    for (int i = 0; i < v.size(); ++i) {
        int l = i, b = v[i].first;
        while(l < v.size()-1 && v[l+1].second.second + 1 == v[l].second.first) l++, b += v[l].first;
        if(b > ans.first) ans = {b, {v[l].second.first, v[i].second.second}};
    }
    cout << ans.first << "\n";
    if(ans.first) for (int i = ans.second.first; i <= ans.second.second; ++i) {
        cout << in[i];
    }
}
