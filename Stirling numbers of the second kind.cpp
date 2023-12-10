#include <iostream>
static const unsigned int NMAX = 20, RMAX = 20;
unsigned long long int fact[NMAX + 1], stirling[NMAX + 1][RMAX + 1], i, j;
int main() {
    fact[0] = fact[1] = 1;
    for (i = 2; i <= NMAX; ++ i)
        fact[i] = fact[i - 1] * i;
    for (i = 0; i <= NMAX; ++ i)
        stirling[i][i] = 1;
    for (i = 1; i <= RMAX; ++ i)
        stirling[1][i] = fact[i - 1];
    for (i = 2; i <= NMAX; ++ i)
        for (j = 2; j <= RMAX; ++ j)
            stirling[i][j] = stirling[i - 1][j - 1] + (j - 1) * stirling[i][j - 1];
    return 0;
}
