#include <iostream>
static const uint32_t NMAX = 26;
uint64_t bell[NMAX + 1], *aux, prev, temp;
uint32_t i, j;
int main() {
    aux = (uint64_t*)calloc(NMAX + 1, sizeof(uint64_t));
    aux[0] = bell[0] = 1;
    for (i = 1; i <= NMAX; ++ i) {
        prev = aux[0];
        aux[0] = aux[i - 1];
        for (j = 1; j <= i; ++ j) {
            temp = aux[j];
            aux[j] = prev + aux[j - 1];
            prev = temp;
        }
        bell[i] = aux[0];
    }
    free(aux);
    return 0;
}
