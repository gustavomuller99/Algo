#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        unsigned long long n; cin>>n;
        set<unsigned long long> c;
        for (unsigned long long i = 1; i*i <= n; ++i) {
            c.insert(i*i);
            if(i*i*i <= n) c.insert(i*i*i);
        }
        cout << c.size() << "\n";
    }
}
