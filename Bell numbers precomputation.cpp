const uint16_t MaxBell = 26;
uint64_t bell[MaxBell + 1];
void precomputeBell() {
	uint64_t aux[MaxBell + 1], prev, temp;
	aux[0] = bell[0] = 1;
	uint16_t i, j;
	for (i = 1; i <= MaxBell; ++ i) {
		prev = aux[0];
		aux[0] = aux[i - 1];
		for (j = 1; j <= i; ++ j) {
			temp = aux[j];
			aux[j] = prev + aux[j - 1];
			prev = temp;
		}
		bell[i] = aux[0];
	}
}
