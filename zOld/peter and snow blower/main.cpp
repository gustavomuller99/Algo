#include <bits/stdc++.h>

using namespace std;
double pi = 3.14159265359;

pair<double, double> intersect(pair<double, double> x, pair<double, double> p1, pair<double, double> p2) {
    if (p2.first < p1.first) swap(p1, p2);
    pair<double, double> r;
    double m1 = (p2.second - p1.second) / (p2.first - p1.first);
    if (m1 < 1e-8) {
        return {x.first, p1.second};
    }
    double k1 = m1 * (-p1.first) + p1.second;
    double m2 = -1 / m1;
    double k2 = m2 * (-x.first) + x.second;
    r.first = (k1 - k2) / (m1 - m2);
    r.second = (k2 * m1 - k1 * m2) / (m1 - m2);
    return r;
}

int main() {
    int n;
    double p1, p2;
    cin >> n >> p1 >> p2;
    double r1 = INT_MAX, r2 = 0;
    vector<pair<double, double>> c(2, {INT_MAX, INT_MAX});
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        r2 = max(r2, (x - p1) * (x - p1) + (y - p2) * (y - p2));
        r1 = min(r1, (x - p1) * (x - p1) + (y - p2) * (y - p2));
        if ((x - p1) * (x - p1) + (y - p2) * (y - p2) <
            (x - c[0].first) * (x - c[0].first) + (y - c[0].second) * (y - c[0].second)) {
            c[1] = c[0], c[0] = {x, y};
        } else if ((x - p1) * (x - p1) + (y - p2) * (y - p2) <
                   (x - c[1].first) * (x - c[1].first) + (y - c[1].second) * (y - c[1].second)) {
            c[1] = {x, y};
        }
    }
    if ((c[0].first - p1) * (c[1].first - p1) < 0 || (c[0].second - p2) * (c[1].second - p2) < 0) {
        auto r = intersect({p1, p2}, c[0], c[1]);
        r1 = min(r1, (p1 - r.first) * (p1 - r.first) + (p2 - r.second) * (p2 - r.second));
    }
    cout << setprecision(20) << pi * (r2 - r1);
}
