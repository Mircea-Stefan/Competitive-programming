#include <iostream>
#include <bitset>
#include <vector>
static const uint32_t NMAX = 1e8;
uint32_t i, j, aux;
std :: bitset <NMAX + 1> sieve;
std :: vector <uint32_t> primes;
int main() {
    sieve[2] = sieve[3] = 1;
    for (i = 1; i * i <= NMAX; ++ i)
        for (j = 1; j * j <= NMAX; ++ j) {
            aux = ((i * i) << 2) + j * j;
            if (aux <= NMAX and (aux % 12 == 1 or aux % 12 == 5))
                sieve[aux] = sieve[aux] ^ 1;
            aux -= i * i;
            if (aux <= NMAX and aux % 12 == 7)
                sieve[aux] = sieve[aux] ^ 1;
            aux -= (j * j) << 1;
            if (i > j and aux <= NMAX and aux % 12 == 11)
                sieve[aux] = sieve[aux] ^ 1;
        }
    for (i = 5; i * i <= NMAX; i += 2)
        if (sieve[i] == 1)
            for (j = i * i; j <= NMAX; j += i * i)
                sieve[j] = 0;
    primes.emplace_back(2);
    for (i = 3; i <= NMAX; i += 2)
        if (sieve[i] == 1)
            primes.emplace_back(i);
    return 0;
}
