#include <iostream>
static const unsigned int NMAX = 36;
unsigned long long int catalan[NMAX + 1];
unsigned int i, j;
int main() {
    catalan[0] = catalan[1] = 1;
    for (i = 2; i <= NMAX; ++ i)
        for (j = 0; j != i; ++ j)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    return 0;
}
