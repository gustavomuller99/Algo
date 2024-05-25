#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> ans(n);
    queue<int> q;
    bool add = false;
    q.push(0);
    for (int i = 1; i < n; ++i) {
        if(s[i-1] == 'R') add = false;
        if(s[i-1] == 'L') add = true;
        if(i < n-1 && s[i] == 'R' && add) q.push(i);
    }
    q.push(n-1);
    while(!q.empty()) {
        int l = q.front(), r = l; q.pop();
        if((l == 0 && s[r] == 'R') || (r == n-1 && s[r-1] == 'L') || (r != 0 && r != n-1)) ans[r] = 1;
        while(l-1 >= 0 && (s[l-1] == 'L' || s[l-1] == '=')) {
            int v = ans[l] + (s[l-1] == 'L' ? 1 : 0);
            ans[l-1] = v;
            l--;
        }
        while(r+1 < n && (s[r] == 'R' || s[r] == '=')) {
            int v = ans[r] + (s[r] == 'R' ? 1 : 0);
            ans[r+1] = v;
            r++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!ans[i]) ans[i] = 1;
        while(i < n-1 && s[i] != 'L') {
            i++;
            int v = ans[i-1] + (s[i-1] == 'R' ? 1 : 0);
            if(v < ans[i]) break;
            ans[i] = v;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if(!ans[i]) ans[i] = 1;
        while(i > 0 && s[i-1] != 'R') {
            i--;
            int v = ans[i+1] + (s[i] == 'L' ? 1 : 0);
            if(v < ans[i]) break;
            ans[i] = v;
        }
    }
    for(int x: ans) cout << x << " ";
}
