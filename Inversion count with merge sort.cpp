#include <iostream>
uint64_t Merge(uint64_t v[], uint64_t aux[], uint32_t l, uint32_t mid, uint32_t r) {
	uint64_t nrInv = 0;
	uint32_t i = l, j = mid, k = l;
	while (i < mid and j <= r) {
		if (v[i] <= v[j]) {
			aux[k] = v[i];
			++ i;
		}
		else {
			aux[k] = v[j];
			++ j;
			nrInv += mid - i;
		}
		++ k;
	}
	while (i < mid) {
		aux[k] = v[i];
		++ i;
		++ k;
	}
	while (j <= r) {
		aux[k] = v[j];
		++ j;
		++ k;
	}
	for (i = l; i <= r; ++ i)
		v[i] = aux[i];
	return nrInv;
}
uint64_t mergeSort(uint64_t v[], uint64_t aux[], uint32_t l, uint32_t r) {
	uint64_t nrInv = 0;
	if (l < r) {
		uint32_t mid = (l + r) >> 1;
		nrInv += mergeSort(v, aux, l, mid);
		nrInv += mergeSort(v, aux, mid + 1, r);
		nrInv += Merge(v, aux, l, mid + 1, r);
	}
	return nrInv;
}
uint64_t countInversions(uint32_t n, uint64_t v[]) {
	uint64_t Copy[n];
	uint32_t i;
	for (i = 0; i < n; ++ i)
		Copy[i] = v[i];
	uint64_t aux[n];
	return mergeSort(Copy, aux, 0, n - 1);
}
int main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(nullptr);
	uint32_t n, i;
	std :: cin >> n;
	uint64_t v[n];
	for (i = 0; i < n; ++ i)
		std :: cin >> i;
	std :: cout << countInversions(n, v);
    return 0;
}
