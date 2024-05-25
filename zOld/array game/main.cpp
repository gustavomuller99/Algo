#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bool w = true;
    vector<int> a(n);
    stack<int> s; s.push(-1);
    int l = n, r = -1, lx = 0, rx = n-1;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 1; i < n && l == n; ++i) if(a[i-1] >= a[i]) l = i;
    for (int i = n-2; i >= 0 && r == -1; --i) if(a[i+1] >= a[i]) r = i;
    while(true) {
        if(a[lx] <= s.top()) {
            if((rx - r) % 2 == 0) w = !w;
            break;
        } else if(a[rx] <= s.top()) {
            if((l - lx) % 2 == 0) w = !w;
            break;
        } else if(a[lx] == a[rx]) {
            if((l - lx) % 2 == 0 && (rx - r) % 2 == 0) w = !w;
            break;
        } else if(a[lx] > a[rx]) {
            if((l - lx) % 2) break;
            else {
                s.push(a[rx]);
                rx--;
            }
        } else {
            if((rx - r) % 2) break;
            else {
                s.push(a[lx]);
                lx++;
            }
        }
        w = !w;
    }
    if(w) cout << "Alice";
    else cout << "Bob";
}
