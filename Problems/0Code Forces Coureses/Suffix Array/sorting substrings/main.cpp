#include <bits/stdc++.h>
using namespace std;

vector<int> p, c, lcp, st((1 << 19) - 1, INT_MAX);
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

int m(int i, int lx, int rx, int l, int r) {
    if(lx > r || rx < l) return INT_MAX;
    if(lx >= l && rx <= r) return st[i];

    int mid = (lx + rx) / 2;
    return min(m(2*i+1, lx, mid, l, r), m(2*i+2, mid+1, rx, l, r));
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    int mn = m(0, 0, st.size() / 2, min(c[a.first], c[b.first]) + 1, max(c[a.first], c[b.first]));
    if ((a.second - a.first + 1) <= mn && (b.second - b.first + 1) <= mn) {
        if(a.second - a.first == b.second - b.first) {
            if(a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        } else return (a.second - a.first) < (b.second - b.first);
    }
    if ((a.second - a.first + 1) <= mn) return true;
    if ((b.second - b.first + 1) <= mn) return false;
    return c[p[c[a.first + mn]]] < c[p[c[b.first + mn]]];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>s; s += ' ';
    sort_suffixes();
    find_lcp();

    for (int i = st.size() / 2; i < st.size() / 2 + lcp.size(); ++i) st[i] = lcp[i - st.size() / 2];
    for (int i = st.size() / 2 - 1; i >= 0; --i) st[i] = min(st[2*i + 1], st[2*i + 2]);

    int n; cin>>n;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; ++i) cin>>t[i].first>>t[i].second, t[i].first--, t[i].second--;
    sort(t.begin(), t.end(), compare);

    for (int i = 0; i < t.size(); ++i) {
        cout << t[i].first + 1 << " " << t[i].second + 1 << "\n";
    }
}
