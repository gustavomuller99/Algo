#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        deque<int> d;
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            if(d.empty() || x > d.front()) d.push_back(x);
            else d.push_front(x);
        }
        while(!d.empty()) {
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << "\n";
    }
}
