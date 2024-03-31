const uint16_t maxCatalan = 35;
uint64_t catalan[maxCatalan + 1];
void precomputeCatalan() {
	catalan[0] = 1;
	uint64_t i;
	for (i = 1; i <= maxCatalan; ++ i)
		catalan[i] = catalan[i - 1] * ((i << 2) - 2) / (i + 1);
}
