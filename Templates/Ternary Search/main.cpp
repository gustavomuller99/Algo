#include <bits/stdc++.h>

using namespace std;

vector<int> a;

/** Basic ternary search for functions with one maximal or minimal */
bool f(int x1, int x2) {
    // greedy solution
    // true if f(x1) < f(x2)
}


void ts() {
    int l = 0, r = a.size();
    // final positions will be (l x r) -> optimal solution is one of the three
    while(r > l + 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if(f(m1, m2)) l = m1;
        else r = m2;
    }
}
