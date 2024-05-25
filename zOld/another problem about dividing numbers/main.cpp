#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

multiset<int> d(int a) {
    multiset<int> r;
    for (int i = 2; i*i <= a; ++i) {
        while(a % i == 0) r.insert(i), a /= i;
    }
    if(a != 1) r.insert(a);
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int a,b,k,mn=2,mx=0; cin>>a>>b>>k;
        int g = gcd(max(a,b),min(a,b));
        multiset<int> da = d(a), db = d(b);
        bool ans = false;
        if(a == g) mn--; if(b == g) mn--;
        mx += da.size() + db.size();
        if((k == 1 && mn == 1) || (k != 1 && k >= mn && k <= mx)) ans = true;
        if(ans) cout << "YES\n";
        else cout << "NO\n";

    }
}
