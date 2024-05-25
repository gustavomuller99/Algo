#include <bits/stdc++.h>
using namespace std;

/* given a diophantine equation ax + by = c, a solution exists if gcd(a,b) | c
 * a solution can be find as d = ax0 + bx0 (see gcd_with_factors()) and
 * c = dt = atx0 + btx0
 * all other solutions are of the form x0 + (b/d)t, y0 - (a/d)t */

/* this function returns the factors gcd(a,b) = c.a + d.b as {gcd, {c, d}} */
pair<int, pair<int, int>> gcd_with_factors(int a, int b) {
    if(b == 0) return {a, {1, 0}};
    else {
        auto p = gcd_with_factors(b, a % b);
        return {p.first, {p.second.second, p.second.first - p.second.second * (a / b)}};
    }
}

/* ax + by = c */
pair<bool, pair<int, int>> d_solution(int a, int b, int c) {
    auto r = gcd_with_factors(a, b);
    return {c % r.first == 0, {(c / r.first) * r.second.first, (c / r.first) * r.second.second}};
}

/* find solutions in an interval */


int main() {
    int a, b, c; cin >> a >> b >> c;
    auto r = d_solution(a, b, c);
    printf("There is a solution? %s\n", (r.first ? "YES" : "NO"));
    printf("One solution is of the form: %d = %d*%d + %d*%d", c, a, r.second.first, b, r.second.second);
}
