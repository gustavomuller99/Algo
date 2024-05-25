#include <bits/stdc++.h>
using namespace std;
string s; int n;

bool f(int x) {
    vector<bool> t(s.size());
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'P') {
            int l = 0;
            for (int j = i-1; j >= 0; --j) {
                if (t[j] || s[j] == 'P') break;
                if (s[j] == '*') {
                    if (t[j]) break;
                    if (i - j <= x) t[j] = true, l = i - j;
                    else break;
                } else t[j] = true;
            }
            for (int j = i+1; j < n; ++j) {
                if (t[j] || s[j] == 'P') break;
                if (s[j] == '*') {
                    if (min(l, j - i) * 2 + max(l, j - i) <= x) t[j] = true;
                    else break;
                } else t[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) if(s[i] == '*' && !t[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>s;
    int l = 0, r = 2*s.size();
    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
