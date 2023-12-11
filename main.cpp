#include <iostream>
static const unsigned long long int NMAX = 8;
long long int RMQ[std :: __lg(NMAX) + 2][NMAX + 1];
unsigned int i, j;
int main() {
    /**
    initialization of RMQ[0]
    */
    for (i = 1; (1 << i) <= NMAX; ++ i)
        for (j = 0; j + (1 << i) <= NMAX; ++ j)
            RMQ[i][j] = std :: min(RMQ[i - 1][j], RMQ[i - 1][j + (1 << (i - 1))]);
    if ((NMAX & (NMAX - 1)) != 0)
        RMQ[i][0] = std :: min(RMQ[i - 1][0], RMQ[i - 1][NMAX - (1 << (i - 1))]);
    return 0;
}
