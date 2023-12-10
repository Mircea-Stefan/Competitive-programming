#include <iostream>
static const unsigned int NMAX = 36;
unsigned long long int catalan[NMAX + 1];
unsigned int i, j;
int main() {
    catalan[0] = 1;
    for (i = 1; i != NMAX; ++ i)
        catalan[i] = catalan[i - 1] * ((i << 2) - 2) / (i + 1);
    return 0;
}
