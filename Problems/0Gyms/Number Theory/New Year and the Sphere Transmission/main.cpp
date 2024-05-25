#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
int main() {
    int n; cin>>n;
    set<ll> ans;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ll inv = n / i;
            ll an = i * (n / i) - i, qtd = (n / i), anv = inv * (n / inv) - inv, qtdv = (n / inv);
            ans.insert(n / i + an * qtd / 2);
            ans.insert(n / inv + anv * qtdv / 2);
        }
    }
    for (ll p : ans) cout << p << " ";
}
