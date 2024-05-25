#include <bits/stdc++.h>
using namespace std;

vector<int> p, c;

void sort_suffixes(string const& s) {
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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin>>s; s += '$';
    sort_suffixes(s);
    int t; cin>>t; while(t--) {
        string b; cin>>b;
        int l1 = 0, l2 = 0, r1 = s.size(), r2 = s.size();
        while(l1 + 1 < r1) {
            int mid = (l1 + r1) / 2;
            if(b < s.substr(p[mid], b.size())) r1 = mid;
            else l1 = mid;
        }
        while(l2 + 1 < r2) {
            int mid = (l2 + r2) / 2;
            if(b <= s.substr(p[mid], b.size())) r2 = mid;
            else l2 = mid;
        }

        if(b == s.substr(p[l1], b.size())) cout << l1 - r2 + 1 << "\n";
        else cout << 0 << "\n";
    }
}