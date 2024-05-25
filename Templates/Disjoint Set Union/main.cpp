#include <bits/stdc++.h>

using namespace std;

vector<int> d; /* d[i] = i */
vector<int> s;

/**
 * basic implementation
 * problems can be solved in reversed order of query */

int get(int n) {
    return d[n] = (n == d[n] ? n : get(d[n]));
}

/** no path compression */

int get2(int u) {
    while (u != d[u]) {
        u = d[u];
    }
    return u;
}

void join(int a, int b) {
    a = get(a); b = get(b);
    if(s[b] > s[a]) swap(a, b);
    s[a] += s[b];
    d[b] = a;
}

/** problems with people ->
 * join neighbour indices in array */
