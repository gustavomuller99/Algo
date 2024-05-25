#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

void solve() {
    ll x;
    cin >> x;
    vector<int> ans;
    int min = 0, max = 200;
    x--;
    while(x) {
        if (x % 2 == 0) {
            ans.push_back(min), min++;
            x--;
        }
        else {
            ans.push_back(max), max--;
            x--, x /= 2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int an : ans) {
        cout << an << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
