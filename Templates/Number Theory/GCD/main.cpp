#include <bits/stdc++.h>
using namespace std;

/**
 * gcd properties:
 * gcd(x, 0) = x
 * gcd(x, x-1) = 1
 * gcd(x, y) = gcd(x - y, y) = gcd(x + y, y) for x >= y
 * gcd(x, y) <= x <= y
 * ax + by = c * gcd(x, y) for all integer (a, b)
 * by % n => by - an */

/* greatest common divisor of two numbers (euclidean algorithm)
 * an upper bound to this algorithm is proven to be at most 5*(number of digits of the smaller number)
 * so not very big */

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

/* this second function returns the factors gcd(a,b) = c.a + d.b as {gcd, {c, d}} */
pair<int, pair<int, int>> gcd_with_factors(int a, int b) {
    if(b == 0) return {a, {1, 0}};
    else {
        auto p = gcd_with_factors(b, a % b);
        return {p.first, {p.second.second, p.second.first - p.second.second * (a / b)}};
    }
}

int lcm(int a, int b) {
    return (a*b / gcd(a,b));
}

int main() {
    int x, y; cin >> x >> y;
    auto p = gcd_with_factors(x, y);
    printf("gcd(%d, %d) = %d = %d*%d + %d*%d\n", x, y, p.first, p.second.first, x, p.second.second, y);
    printf("lcm(%d, %d) = %d", x, y, lcm(x, y));
}
