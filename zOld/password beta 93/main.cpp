#include <bits/stdc++.h>
using namespace std;

vector<int> p;
void kmp(const string& s) {
    p = vector<int> (s.size());
    p[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }
}

int main() {
    string s, ans = "Just a legend"; cin>>s;
    vector<int> d(s.size() + 1);
    if(s.size() > 1) kmp(s.substr(0, s.size() - 1));
    for (int i : p) if(i) d[i]++;
    kmp(s);
    int j = s.size();
    while(j > 0) {
        if(d[p[j-1]]) {
            ans = s.substr(0, p[j-1]);
            break;
        }
        j = p[j-1];
    }
    cout << ans;
}
