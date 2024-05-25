#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        ll n, c = 0; cin>>n; vector<ll> a(n+1);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x; a[x]++;
        }
        stack<int> s;
        vector<ll> ans;
        for (int i = 0; i <= n; ++i) {
            if(c > -1) ans.push_back(c + a[i]);
            else ans.push_back(-1);

            if(a[i] == 0 && s.empty()) c = -1;
            else if(a[i] == 0 && c != -1) {
                c += i - s.top(); s.pop();
            } else for (int j = 1; j < a[i]; ++j) {
                s.push(i);
            }
        }
        for (int i = 0; i <= n; ++i) {
            cout << ans[i] << " ";
        } cout << "\n";
    }
}
