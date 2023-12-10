unsigned long long int ext_gcd(unsigned long long int a, unsigned long long int b, unsigned long long int &x, unsigned long long int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    unsigned long long int x1, y1, gcd = ext_gcd(b % a, a, x1, y1);
    x = y1 - b / a * x1;
    y = x1;
    return gcd;
}
