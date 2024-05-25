#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> n(4, vector<int> ());
    for (int i = 0; i < 4; ++i) {
        int x; cin>>x; n[i].resize(x);
        for (int j = 0; j < x; ++j) cin>>n[i][j];
        sort(n[i].begin(), n[i].end());
    }
    int ans = INT_MAX, sh = 0;
    vector<int> p(4);
    for (int i = 0; i < 4; ++i) {
        int l1 = n[i].size() - 1,
            l2 = n[(i+1)%4].size() - 1,
            l3 = n[(i+2)%4].size() - 1,
            l4 = n[(i+3)%4].size() - 1;
        while(l1 >= 0) {
            while(l2 > 0 && n[(i+1)%4][l2] > n[i][l1]) l2--;
            while(l3 > 0 && n[(i+2)%4][l3] > n[i][l1]) l3--;
            while(l4 > 0 && n[(i+3)%4][l4] > n[i][l1]) l4--;
            if(max(n[i][l1], max(n[(i+1)%4][l2], max(n[(i+2)%4][l3], n[(i+3)%4][l4]))) - min(n[i][l1], min(n[(i+1)%4][l2], min(n[(i+2)%4][l3], n[(i+3)%4][l4]))) < ans) {
                   ans = max(n[i][l1], max(n[(i+1)%4][l2], max(n[(i+2)%4][l3], n[(i+3)%4][l4]))) - min(n[i][l1], min(n[(i+1)%4][l2], min(n[(i+2)%4][l3], n[(i+3)%4][l4])));
                   p = {n[i][l1], n[(i+1)%4][l2], n[(i+2)%4][l3], n[(i+3)%4][l4]};
                   sh = 4-i;
            }
            l1--;
        }
    }
    for (int i = 0; i < 4; ++i) {
        cout << p[(i+sh)%4] << " ";
    }
}
