#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<long long> last(27, -1), k(27);
    for (int i = s.size(); i >= 0; --i) {
        last[s[i] - 'a'] = i;
        vector<long long> v;
        for (int j = 0; j < 27; ++j) if (last[j] != -1) v.push_back(last[j]);
        sort(v.begin(), v.end());
        v.push_back(s.size());
        for (int j = 0; j < v.size() - 1; ++j) k[j] += v[j+1] - v[j];
    }
    int ans;
    for (int i = 0; i < 27; ++i) if (k[i]) ans = i;
    cout << ans + 1 << "\n";
    for (int i = 0; i <= ans; ++i) cout << k[i] << "\n";
}
