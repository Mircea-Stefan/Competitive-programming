#include <iostream>
void printArr(uint16_t n, uint64_t v[]) {
    for (uint16_t i = 0; i < n; ++ i)
        std :: cout << v[i] << ' ';
    std :: cout << '\n';
}
void heapPermutation(uint16_t n, uint64_t v[], uint16_t pos) {
    if (pos == 1) {
        printArr(n, v);
        return;
    }
    for (uint16_t i = 0; i < pos; ++ i) {
        heapPermutation(n, v, pos - 1);
        if ((pos & 1) == 1)
            std :: swap(v[0], v[pos - 1]);
        else
            std :: swap(v[i], v[pos - 1]);
    }
}
int main() {
	std :: ios_base :: sync_with_stdio(false);
	std :: cin.tie(nullptr);
	uint16_t n;
    std :: cin >> n;
    uint64_t v[n];
    for (uint16_t i = 0; i < n; ++ i)
        std :: cin >> v[i];
    heapPermutation(n, v, n);
    return 0;
}
