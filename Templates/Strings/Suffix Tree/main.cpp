#include <bits/stdc++.h>
using namespace std;

const int N = 1000000, INF = 1000000000;
string a;
int t[N][26], l[N], r[N], p[N], s[N];
int curr, len, n, curr_c;

void ukkadd(int c) {
    suff:;
    if (r[curr] < len) {
        if (t[curr][c] == -1) {
            t[curr][c] = n;
            l[n] = curr_c;
            p[n++] = curr;
            curr = s[curr];
            len = r[curr] + 1;
            goto suff;
        }
        curr = t[curr][c];
        len = l[curr];
    }
    if (len == -1 || c == a[len] - 'a') len++;
    else {
        l[n + 1] = curr_c;
        p[n + 1] = n;
        l[n] = l[curr];
        r[n] = len - 1;
        p[n] = p[curr];
        t[n][c] = n + 1;
        t[n][a[len] - 'a'] = curr;
        l[curr] = len;
        p[curr] = n;
        t[p[n]][a[l[n]] - 'a'] = n;
        n += 2;
        curr = s[p[n - 2]];
        len = l[n - 2];
        while (len <= r[n - 2]) {
            curr = t[curr][a[len] - 'a'];
            len += r[curr] - l[curr] + 1;
        }
        if (len == r[n - 2] + 1) s[n - 2] = curr; else s[n - 2] = n;
        len = r[curr] - (len - r[n - 2]) + 2;
        goto suff;
    }
}

void build() {
    n = 2;
    curr = 0;
    len = 0;
    fill(r, r + N, (int) a.size() - 1);
    s[0] = 1;
    l[0] = -1;
    r[0] = -1;
    l[1] = -1;
    r[1] = -1;
    memset(t, -1, sizeof t);
    fill(t[1], t[1] + 26, 0);
    for (curr_c = 0; curr_c < (int) a.size(); ++curr_c)
        ukkadd(a[curr_c] - 'a');
}