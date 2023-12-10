#include <ctime>
inline unsigned long long int lg_pow(unsigned long long int x, unsigned long long int p, unsigned long long int &MOD) {
    unsigned long long int ans = 1;
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
const unsigned long long int bigPrime = 666013;
inline unsigned long long int Rand(unsigned long long int Max) {
    unsigned long long int ans = bigPrime % Max * ((unsigned long long int)rand() % Max * (rand() % Max) % Max  + rand() % Max) % Max + rand() % Max;
    ans %= Max;
    return ans;
}
inline bool MillerRabin(unsigned long long int d, unsigned long long int &n) {
    unsigned long long int a = 2 + Rand(n - 4), x = lg_pow(a, d, n);
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
inline bool isPrime(unsigned long long int n, unsigned long long int k) {
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
