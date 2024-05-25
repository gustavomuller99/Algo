#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin>>t; while(t--) {
        string a, b, ans;
        cin>>a>>b;
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0) {
            if(j < 0) { ans = "-1"; break; }
            if(a[i] <= b[j]) {
                ans = (char) (b[j] - a[i] + '0') + ans;
            } else {
                j--;
                if(j < 0) continue;
                int y = (b[j] - '0') * 10 + (b[j+1] - '0'), x = a[i] - '0';
                if(y >= 10 && y <= 18) {
                    ans = (char) (y - x + '0') + ans;
                } else { ans = "-1"; break; }
            }
            i--, j--;
        }
        if(ans != "-1") while(j >= 0) ans = b[j] + ans, j--;
        while(ans[0] == '0') ans.erase(0, 1);
        cout << ans << "\n";
    }
}
