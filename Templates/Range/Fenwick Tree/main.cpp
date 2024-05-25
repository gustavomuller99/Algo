#include <bits/stdc++.h>
using namespace std;

/* each position p keeps the values of the last
 * n elements, where n is the less significant bit unset in p
 * fit for any operation of the type (0, r)
 * and operations (l, r) that can be canceled, such as -, +
 * */

vector<int> f;

/* point update and range query */
void add(int i, int x) {
    while(i < f.size()) {
        f[i] += x;
        i = i | (i + 1);
    }
}
int get(int i) {
    int r = 0;
    while(i >= 0) {
        r += f[i];
        i = (i & (i + 1)) - 1;
    }
    return r;
}

