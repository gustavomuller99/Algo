#include <bits/stdc++.h>
using namespace std;
vector<int> s;
int k, q, n; string in;
void u(int i, char c) {
    switch (c) {
        case '0': {
            if(2*i < n-1) s[i] = s[2*i+2];
            else s[i] = 1;
            break;
        }
        case '1': {
            if(2*i < n-1) s[i] = s[2*i+1];
            else s[i] = 1;
            break;
        }
        default: {
            if(2*i < n-1) s[i] = s[2*i+2] + s[2*i+1];
            else s[i] = 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>k>>in>>q;
    n = (1 << k) - 1;
    s.resize(n);
    for (int i = 0; i < in.size(); ++i) u(n-i-1, in[i]);
    while(q--) {
        int p; char c; cin>>p>>c;
        in[p-1] = c;
        int index = n-p;
        u(index, in[in.size() - index - 1]);
        while(index != 0) {
            index = index/2 - (index%2 == 0);
            u(index, in[in.size() - index - 1]);
        }
        cout << s[0] << "\n";
    }
}
