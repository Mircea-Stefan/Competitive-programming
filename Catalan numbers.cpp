#include <iostream>
static const uint32_t NMAX = 36;
uint64_t catalan[NMAX + 1];
uint32_t i, j;
int main() {
    catalan[0] = 1;
    for (i = 1; i != NMAX; ++ i)
        catalan[i] = catalan[i - 1] * ((i << 2) - 2) / (i + 1);
    return 0;
}
