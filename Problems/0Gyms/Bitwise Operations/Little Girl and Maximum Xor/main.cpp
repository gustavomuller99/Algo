#include <bits/stdc++.h>

// https://codeforces.com/gym/344975/problem/E

using namespace std;
#define ll unsigned long long

int main() {
    ll l, r, ans;
    cin >> l >> r;
    int k = 0;
    while (r >= (1ll << k)) k++;
    while (k >= 0) {
        if ((r & (1ll << k)) != (l & (1ll << k))) break;
        k--;
    }
    ans = r ^ l;
    for (int i = 0; i <= k; ++i) {
        if ((ans & (1ll << i)) == 0) ans += (1ll << i);
    }
    cout << ans;
}
