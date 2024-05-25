#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    vector<ll> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(), a.end());
    if(a[2] > 2*(a[0] + a[1])) cout << a[0] + a[1];
    else cout << (a[0] + a[1] + a[2]) / 3;
}
