#include <bits/stdc++.h>

using namespace std;
vector<int> d_odd, d_even;

/** manacher algo for finding palindromes in substrings
 * d_odd[i] = x -> palindrome centered at i with length 2*x - 1
 * d_even[i] = x -> palindrome centered at i and i-i with length 2*x */

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void manacher(string s) {
    string t;
    for (auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    d_odd = d_even = vector<int>(s.size() + 1);
    for (int i = 0; i < res.size(); ++i) {
        if (i % 2) d_odd[(i - 1) / 2] = res[i] / 2;
        else d_even[i / 2] = (res[i] - 1) / 2;
    }
}