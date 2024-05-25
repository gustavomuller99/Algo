#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int x,cnt=0; cin>>x;
        if(x%2) cout << "Bob\n";
        else {
            while(x%2==0) x/=2,cnt++;
            if(x!=1) cout << "Alice\n";
            else if(cnt%2) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }
}
