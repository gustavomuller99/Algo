#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,m,ans=0; cin>>n>>m;
        vector<pair<ll, int>> in(n*m);
        for (int i = 0; i < n*m; ++i) {
            cin>>in[i].first; in[i].second=i;
        }
        sort(in.begin(), in.end());
        for (int i = 0; i < n; ++i) {
            sort(in.begin(), in.begin()+m-1);
            for (int j = i*m; j < (i+1)*m; ++j) {
                for (int k = i*m; k < j; ++k)
                    if(in[k].second < in[j].second && in[k].first != in[j].first) ans++;
            }
        }
        cout << ans << "\n";
    }
}
