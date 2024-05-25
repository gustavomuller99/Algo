#include <bits/stdc++.h>
using namespace std;

/* given a string and a pattern,
 * z-function works like prefix-function, only inverted
 * z[i] = largest prefix that is also a suffix starting at i
 * it achieves linear time by initializing z[i] with previous computed values
 */

string s;
vector<int> z;

vector<int> z_function() {
    int n = s.size();
    z = vector<int> (n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
