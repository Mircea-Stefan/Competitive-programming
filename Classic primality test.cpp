bool isPrime(uint64_t x) {
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if ((x & 1) == 0)
        return false;
    for (uint64_t d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}
