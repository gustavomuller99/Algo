#include <bits/stdc++.h>
using namespace std;
struct p{int x,y,z;};

double dist(p a, p b) {return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<p> a(n);
    double ans = INT_MAX;
    for (int i = 0; i < n; ++i) cin>>a[i].x>>a[i].y>>a[i].z;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if(i == j) continue;
            double d = (dist(a[i], a[0]) + dist(a[j], a[0]) + dist(a[i], a[j])) / 2;
            if(ans - d > 1e-8) ans = d;
        }
    }
    cout << setprecision(20) << ans;
}
