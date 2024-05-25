#include <bits/stdc++.h>
using namespace std;
vector<int> x(5000001), y(5000001);
int main() {
    int n, sum; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            sum = a[i] + a[j];
            if(x[sum] && x[sum] != i && x[sum] != j && y[sum] && y[sum] != i && y[sum] != j) {
                cout << "YES\n";
                cout << x[sum] << " " << y[sum] << " " << i << " " << j;
                return 0;
            } else x[sum] = i, y[sum] = j;
        }
    }
    cout << "NO\n";
}
