#include <bits/stdc++.h>
using namespace std;

/* naive sieve of eratosthenes, gets all primes up to n
 * second for is allowed to start at i*i because all smaller multiples
 * have already been marked
 * time complexity: n*log^2(sqrt(n)) */
vector<bool> sieve(int n) {
    vector<bool> p(n, true);
    for (int i = 2; i*i <= n; ++i) {
        if(!p[i]) continue;
        for (int j = i*i; j <= n; j += i) {
            p[j] = false;
        }
    }
    return p;
}

/* linear sieve of eratosthenes
 * lowest_factor holds the lowest prime factor of number i
 * linear since the second for sets lowest_factor once for each composite number:
 * every composite number x has ONE representation as lowest_prime[x] * i such that
 * lowest_prime[i] >= lowest_prime[x] */
void linear_sieve(int n) {
    vector<int> primes, lowest_factor(n + 1);
    for (int i = 2; i <= n; ++i) {
        if(lowest_factor[i] == 0) {
            primes.push_back(i);
            lowest_factor[i] = i;
        }
        for(int j = 0; j < primes.size() && primes[j] <= lowest_factor[i] && i * primes[j] <= n; j++)
            lowest_factor[i * primes[j]] = primes[j];
    }
}

/* simple prime check */
bool prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

/* simple factorization */
vector<int> fact(int n) {
    vector<int> factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for (int i = 3; i*i <= n; i += 2) {
        while(n % i == 0) factors.push_back(i), n /= i;
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

