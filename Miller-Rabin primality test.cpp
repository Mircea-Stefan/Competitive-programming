#include <iostream>
#include <ctime>
uint64_t lg_pow(uint64_t x, uint64_t p, uint64_t &MOD) {
    uint64_t ans = 1;
    x %= MOD;
    while (p != 0) {
        if (p & 1) {
            ans *= x;
            ans %= MOD;
        }
        p >>= 1;
        x *= x;
        x %= MOD;
    }
    return ans;
}
const uint64_t bigPrime = 666013;
uint64_t Rand(uint64_t Max) {
    uint64_t ans = bigPrime % Max * ((uint64_t)rand() % Max * (rand() % Max) % Max  + rand() % Max) % Max + rand() % Max;
    ans %= Max;
    return ans;
}
bool MillerRabin(uint64_t d, uint64_t &n) {
    uint64_t a = 2 + Rand(n - 4), x = lg_pow(a, d, n);
    if (x == 1 or x == n - 1)
        return true;
    while (d != n - 1) {
        x *= x;
        x %= n;
        d <<= 1;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}
bool isPrime(uint64_t n, uint64_t k) {
    if (n <= 1)
        return false;
    if (n == 2 or n == 3)
        return true;
    if ((n & 1) == 0)
        return false;
    unsigned long long int d = n - 1;
    while ((d & 1) == 0)
        d >>= 1;
    for (; k != 0; -- k)
        if (MillerRabin(d, n) == 0)
            return false;
    return true;
}
int main() {
    srand(time(NULL));
    return 0;
}
