#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<pair<int, int>> m;
    for (int i = 1; i <= n / 2; ++i)
        for (int j = n / 2 + 1; j <= n; ++j)
            m.emplace_back(i, j), cnt++;
    cout << cnt << "\n";
    for (int i = 0; i < m.size(); ++i)
        cout << m[i].first << " " << m[i].second << "\n";
}
