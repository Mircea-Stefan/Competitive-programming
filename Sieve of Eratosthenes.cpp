#include <bitset>
#include <vector>
const uint32_t NMAX = 1e8;
std :: bitset <(NMAX >> 1) + 1> sieve;
std :: vector <uint32_t> primes;
void precomputePrimes() {
	uint32_t i, j;
	for (i = 3; i * i <= NMAX; i += 2)
		if (sieve[i >> 1] == 0) {
			for (j = i * i; j <= NMAX; j += i << 1)
				sieve[j >> 1] = 1;
		}
	primes.emplace_back(2);
	for (i = 3; i <= NMAX; i += 2)
		if (sieve[i >> 1] == 0)
			primes.emplace_back(i);
}
