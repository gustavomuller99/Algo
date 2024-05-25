#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n, ans = 1, ansop;
    cin >> n;;
    multiset<int> fact;
    for (int i = 2; i*i <= n; ++i) {
        while (n % i == 0) fact.insert(i), n /= i;
    }
    if (n > 1) fact.insert(n);
    int prev = 1, cnt = 1, maxop = 1, minop = fact.size() + 1;
    for (int f : fact) {
        if (f != prev) {
            ans *= f;
            maxop = max(maxop, cnt);
            if (prev != 1) minop = min(minop, cnt);
            prev = f;
            cnt = 0;
        }
        cnt++;
    }
    maxop = max(maxop, cnt);
    minop = min(minop, cnt);
    ansop = (__builtin_popcount(maxop) == 1 ? 32 : 33) - (__builtin_clz(maxop));
    if (maxop == minop && __builtin_popcount(maxop) == 1) ansop--;
    cout << ans << " " << ansop << "\n";
}
