int64_t extGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int64_t x1, y1, gcd = extGCD(b % a, a, x1, y1);
    x = y1 - b / a * x1;
    y = x1;
    return gcd;
}
