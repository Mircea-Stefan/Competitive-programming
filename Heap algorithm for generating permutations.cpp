#include <iostream>
long long int v[1000];
unsigned short n;
inline void printArr() {
    for (unsigned char i = 0; i != n; ++ i)
        std :: cout << v[i] << ' ';
    std :: cout << '\n';
}
inline void heapPermutation(unsigned char sz) {
    if (sz == 1) {
        printArr();
        return;
    }
    for (unsigned char i = 0; i != sz; ++ i) {
        heapPermutation(sz - 1);
        if ((sz & 1) == 1)
            std :: swap(v[0], v[sz - 1]);
        else
            std :: swap(v[i], v[sz - 1]);
    }
}
int main() {
    std :: cin >> n;
    for (unsigned short i = 0; i != n; ++ i)
        std :: cin >> v[i];
    heapPermutation(n);
    return 0;
}
