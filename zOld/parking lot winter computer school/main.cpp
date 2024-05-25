#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int l,b,f,n; cin>>l>>b>>f>>n;
    set<pair<int, int>> s;
    vector<pair<int, int>> a;
    while(n--) {
        int t, x; cin>>t>>x;
        if(t == 1) {
            int d = -1;
            if(l < x) { }
            else if(s.empty())
                d = 0,
                a.emplace_back(0, x-1),
                s.insert({0, x-1});
            else {
                if(s.begin()->first >= x+f)
                    d = 0,
                    a.emplace_back(0, x-1),
                    s.insert({0, x-1});
                if(d == -1) for(auto i = s.begin(); i != (--s.end()) && d == -1; i++) {
                    auto j = ++i; --i; int lo = i->second, hi = j->first;
                    if(hi-lo-1 >= x+b+f)
                        d = lo+b+1,
                        a.emplace_back(lo+b+1, lo+b+x),
                        s.insert({lo+b+1, lo+b+x});
                }
                if(d == -1 && l - ((--s.end())->second)-1 >= x+b)
                    d = (--s.end())->second+b+1,
                    a.emplace_back((--s.end())->second+b+1, (--s.end())->second+b+x),
                    s.insert({(--s.end())->second+b+1, (--s.end())->second+b+x});
            }
            if(d == -1) a.emplace_back();
            cout << d << "\n";
        } else {
            a.emplace_back();
            s.erase(a[x-1]);
        }
    }
}
