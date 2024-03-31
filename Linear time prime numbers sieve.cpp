#include <bitset>
#include <vector>
const uint32_t NMAX = 1e7;
std :: bitset <NMAX + 1> sieve;
std :: vector <uint32_t> primes;
void precomputePrimes() {
	uint32_t i, j;
	primes.emplace_back(2);
    for (i = 3; i <= NMAX; i += 2) {
        if (sieve[i] == 0)
            primes.emplace_back(i);
        for (j = 1; j < primes.size() and i * primes[j] <= NMAX; ++ j)
            sieve[i * primes[j]] = 1;
    }
}
