inline bool isPrime(unsigned long long int x) {
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if ((x & 1) == 0)
        return false;
    for (unsigned long long int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}
