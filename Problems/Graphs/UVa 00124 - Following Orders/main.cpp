#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> g;
vector<int> used;
string line;
char str[27];
int cnt;

void topo(int i, int cur = 0) {
    str[cur] = i + 'a';

    if (cur == cnt - 1) {
        str[cur + 1] = '\0';
        cout << str << "\n";
    }

    used[i] = 2;
    for (int j = 0; j < 26; ++j) {
        if (used[j] == 1) {
            bool add = true;
            for (int k = 0; k < 26; ++k) {
                if (used[k] == 2 && g[{j, k}] == 1) add = false;
            }
            if (add) topo(j, cur + 1);
        }
    }
    used[i] = 1;
}

int main() {
    bool nl = false;
    while (getline(cin, line)) {
        if (nl) cout << "\n";
        nl = true;

        cnt = 0;
        used = vector<int>(26);
        g = map<pair<int, int>, int>();

        istringstream istream(line);
        char ch1, ch2;
        while (istream >> ch1) used[ch1 - 'a'] = 1, cnt++;

        getline(cin, line);
        istream = istringstream(line);
        while (istream >> ch1 >> ch2) {
            g[{ch1 - 'a', ch2 - 'a'}] = 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (used[i]) topo(i);
        }
    }
}
