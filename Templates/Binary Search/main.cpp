#include <bits/stdc++.h>

using namespace std;

vector<int> a;

/** Basic
 * Closest to the left and right of x: y y x x x z
 *                                       ^       ^
 */

int left(int x) {
    int l = -1, r = a.size();
    while (r > l + 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int right(int x) {
    int l = -1, r = a.size();
    while (r > l + 1) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

/** Min or Max problems (linear / step functions)
 *  f(x) -> greedy true of false
 *  */

bool f(int x) {
    // greedy solution
}

int opt() {
    int l = 0, r = 1;
    while(f(r)) r *= 2;
    while(r > l + 1) {
        int mid = (r + l) / 2;
        // if(f(mid)) l = mid; -> 1 1 1 0 0 0
        // if(!f(mid)) l = mid; -> 0 0 0 1 1 1
        // else r = mid;
    }
    /* fractional answer */
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
    }
}

/** Minmax problems
 * min(max(f(x)) or vice versa
 * in opt() binary search on the min() -> O(logn)
 * in f(x) check if the max() satisfies the current mid value -> O(n)
 * functions same as above
 * ex: split array in k segments so that the max sum is min possible,
 * - min(max sum) -> 0 0 1 1, each sum cannot surpass mid */

/** Maximal average
 * works also for other functions: max/min a function in a range in an array.
 * -> rewrite so that given mid, sum(elements) >= / <= 0.
 * same structure as above, but we have to find max(avg) / min(avg) of elements.
 * binary search on the average (ai - x) >= 0 / <= 0.
 */

/** Finding the kth element
 * same structure as above, find the kth element in ascending order in a set of arrays.
 * f(x) - for each array count the number of elements less than mid. -> 1 1 1 0 0 0
 */