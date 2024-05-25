#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(s.size());
        for (int i = 2; i < s.size(); ++i) {
            if (s.substr(i - 2, 3) == "pie" || s.substr(i - 2, 3) == "map") {
                cnt[i - 2]++, cnt[i - 1]++, cnt[i]++;
            }
        }
        vector<int> minv(5);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'm' && cnt[i]) minv[0]++;
            if (s[i] == 'a' && cnt[i]) minv[1]++;
            if (s[i] == 'p' && cnt[i]) minv[2]++;
            if (s[i] == 'i' && cnt[i]) minv[3]++;
            if (s[i] == 'e' && cnt[i]) minv[4]++;
        }
        cout << min(minv[2],
                    min(minv[0] + minv[3],
                        min(minv[0] + minv[4], min(
                                minv[1] + minv[3], minv[1] + minv[4])))) << "\n";
    }
}
