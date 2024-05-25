#include <bits/stdc++.h>

using namespace std;

vector<int> p; // size of largest prefix that is also a suffix at i
void kmp(const string &s) {
    p.resize(s.size());
    p[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int j = p[i - 1]; // size largest prefix at previous position
        while (j > 0 && s[i] != s[j]) // s[j] is the next char in the prefix
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
}
