#include <iostream>
#include <vector>
static const uint32_t NMAX = 1e7;
uint32_t sieve[NMAX + 1], i, j;
std :: vector <uint32_t> primes;
int main() {
    for (i = 2; i <= NMAX; ++ i) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.emplace_back(i);
        }
        for (j = 0; i * primes[j] <= NMAX and j != primes.size(); ++ j)
            sieve[i * primes[j]] = primes[j];
    }
    return 0;
}
