#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/gym/344975/problem/G

pair<string, string> dep[5005];
string op[5005];
vector<int> mem;
map<string, int> idx;
int n, m, qval, bit;

int get(int i) {
    if (i == 0) return qval;
    if (mem[i] != -1) return mem[i];

    if (dep[i].second == "-1") return dep[i].first[bit] - '0';
    else {
        if (op[i] == "XOR") return mem[i] = get(idx[dep[i].first]) ^ get(idx[dep[i].second]);
        if (op[i] == "AND") return mem[i] = get(idx[dep[i].first]) & get(idx[dep[i].second]);
        if (op[i] == "OR") return mem[i] = get(idx[dep[i].first]) | get(idx[dep[i].second]);
    }

    return mem[i];
}

int count(int val) {
    qval = val;
    mem = vector<int>(5005, -1);
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        cnt += get(i);
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string s, t;
        getline(cin, s);

        istringstream is(s);

        vector<string> line;
        while (is >> t) line.push_back(t);

        if (line.size() == 3) {
            dep[i + 1] = {line[2], "-1"};
        } else {
            dep[i + 1] = {line[2], line[4]};
            op[i + 1] = line[3];
        }

        idx[line[0]] = i + 1;
    }

    string maxv, minv;

    for (int i = 0; i < m; ++i) {
        bit = i;

        int cnt0 = count(0);
        int cnt1 = count(1);

        if (cnt0 >= cnt1) maxv.push_back('0');
        else maxv.push_back('1');

        if (cnt1 >= cnt0) minv.push_back('0');
        else minv.push_back('1');
    }

    cout << minv << "\n" << maxv;
}


