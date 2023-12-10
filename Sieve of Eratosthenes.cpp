#include <iostream>
#include <bitset>
#include <vector>
static const unsigned long long int NMAX = 1e8;
unsigned long long int i, j;
std :: bitset <(NMAX >> 1) + 1> sieve;
std :: vector <unsigned long long int> primes;
int main() {
    for (i = 3; i * i <= NMAX; i += 2)
        if (sieve[i >> 1] == 0)
            for (j = i * i; j <= NMAX; j += (i << 1))
                sieve[j >> 1] = 1;
    primes.emplace_back(2);
    for (i = 3; i <= NMAX; i += 2)
        if (sieve[i >> 1] == 0)
            primes.emplace_back(i);
    return 0;
}
