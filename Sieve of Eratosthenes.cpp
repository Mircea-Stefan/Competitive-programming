#include <iostream>
#include <bitset>
#include <vector>
static const uint32_t NMAX = 1e8;
uint32_t i, j;
std :: bitset <(NMAX >> 1) + 1> sieve;
std :: vector <uint32_t> primes;
int main() {
    primes.emplace_back(2);
    primes.emplace_back(3);
    for (j = 9; j <= NMAX; j += 6)
        sieve[j >> 1] = 1;
    for (i = 5; i * i <= NMAX; i += 4) {
        if (sieve[i >> 1] == 0) {
            primes.emplace_back(i);
            for (j = i * i; j <= NMAX; j += (i << 1))
                sieve[j >> 1] = 1;
        }
        i += 2;
        if (sieve[i >> 1] == 0) {
            primes.emplace_back(i);
            for (j = i * i; j <= NMAX; j += (i << 1))
                sieve[j >> 1] = 1;
        }
    }
    for (i = primes.back() + 2; i <= NMAX; i += 2)
        if (sieve[i >> 1] == 0)
            primes.emplace_back(i);
    return 0;
}
