#include <iostream>
static const unsigned int NMAX = 26;
unsigned long long int bell[NMAX + 1], *aux, prev, temp;
unsigned int i, j;
int main() {
    aux = (unsigned long long int*)calloc(NMAX + 1, sizeof(unsigned long long int));
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
