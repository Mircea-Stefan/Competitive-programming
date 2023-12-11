#include <iostream>
int64_t v[1000];
uint8_t n;
void printArr() {
    for (uint8_t i = 0; i != n; ++ i)
        std :: cout << v[i] << ' ';
    std :: cout << '\n';
}
void heapPermutation(uint8_t sz) {
    if (sz == 1) {
        printArr();
        return;
    }
    for (uint8_t i = 0; i != sz; ++ i) {
        heapPermutation(sz - 1);
        if ((sz & 1) == 1)
            std :: swap(v[0], v[sz - 1]);
        else
            std :: swap(v[i], v[sz - 1]);
    }
}
int main() {
    std :: cin >> n;
    for (uint8_t i = 0; i != n; ++ i)
        std :: cin >> v[i];
    heapPermutation(n);
    return 0;
}
