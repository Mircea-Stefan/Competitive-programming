unsigned long long int lg_pow(unsigned long long int x, char pow) {
    unsigned long long int ans = 1;
    while (pow != 0) {
        if (pow & 1)
            ans *= x;
        x *= x;
        pow >>= 1;
    }
    return ans;
}
