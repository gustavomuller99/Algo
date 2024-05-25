#include <bits/stdc++.h>
using namespace std;

vector<int> p, c, lcp;
string s;

void sort_suffixes() {
    int n = s.size();
    const int alphabet = 256;

    vector<int> cnt(max(alphabet, n), 0);
    p.resize(n), c.resize(n);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
}

void find_lcp() {
    lcp.resize(s.size());
    int k = 0;
    for (int i = 0; i < p.size() - 1; ++i) {
        int pi = c[i], j = p[pi - 1];
        while(s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k - 1, 0);
    }
}

int main() {
    string a, b; cin>>a>>b;
    s = a + '$' + b + '#';
    sort_suffixes();
    find_lcp();
    int ans = 0, k;
    for (int i = 2; i < s.size(); ++i) {
        if(((p[i] > a.size() && p[i-1] < a.size()) ||
            (p[i] < a.size() && p[i-1] > a.size())) &&
            lcp[i] > ans) {

            ans = lcp[i];
            k = p[i];

        }
    }
    for (int i = k; i < k + ans; ++i) {
        cout << s[i];
    }
}
