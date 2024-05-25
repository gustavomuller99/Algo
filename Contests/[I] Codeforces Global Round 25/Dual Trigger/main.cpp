#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0, d = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt += s[i] == '1';
            if (i && s[i] == '1' && s[i - 1] == '1') d = 1;
        }
        if (cnt % 2 == 0 && !(cnt == 2 && d)) cout << "YES\n";
        else cout << "NO\n";
    }
}
