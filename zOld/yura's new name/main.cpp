#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '_' && s[i - 1] == '_') ans++;
        }
        ans += (s[0] == '_');
        ans += (s[s.size() - 1] == '_');
        ans += (s.size() == 1 && s[0] == '^');
        cout << ans << "\n";
    }
}
