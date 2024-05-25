#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n;
ll d(ll c, ll k, ll am) {
    if(c == n) return 0;
    if(k == 0) return INT_MAX;
    ll t = 0;
    if(c > n) {
        while(c > n) c -= k, t += am;
        return min(t + d(c, k/10, am-1), t - am + d(c+k, k/10, am-1));
    } else {
        while(c < n) c += k, t += am;
        return min(t + d(c, k/10, am-1), t - am + d(c-k, k/10, am-1));
    }
}

int main() {
    cin>>n; ll k=1, am = 1, cnt=0, c = n;
    while(c != 0) c /= 10, cnt++;
    while(--cnt) k*=10, k++, am++;
    cout << min(d(0, k, am), d(k*10+1, k, am) + am+1) << "\n";
}
