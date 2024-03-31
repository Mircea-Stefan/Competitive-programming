int64_t fastExp(int64_t x, uint16_t pow) {
	int64_t ans = 1;
    while (pow != 0) {
        if ((pow & 1) == 1)
            ans *= x;
        x *= x;
        pow >>= 1;
    }
    return ans;
}
