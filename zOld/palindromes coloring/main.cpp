#include <bits/stdc++.h>
using namespace std;
vector<int> a(27);
int n, k;
bool f(int x) {
    vector<int> c = a;
    bool r = true;
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        int s = 0;
        for (int j = 0; j < c.size() && s < x; ++j) {
            int d = min(x - s - (x - s) % 2, c[j] - c[j] % 2);
            s += d, c[j] -= d;
        }
        if(x - s > 1) r = false;
        if(x - s == 1) cnt++;
    }
    return r && cnt <= accumulate(c.begin(), c.end(), 0);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        cin>>n>>k;
        string s; cin>>s;
        a = vector<int> (27);
        for(char b : s) a[b-'a']++;
        int l = 0, r = n + 2;
        while(l + 1 < r) {
            int mid = (l + r) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
}
