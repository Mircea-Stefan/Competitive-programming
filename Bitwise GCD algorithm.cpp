#include <iostream>
#pragma GCC target("abm", "bmi", "bmi2", "popcnt", "lzcnt")
uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == 1 or b == 1)
        return 1;
    char shift = __builtin_ctz(a | b), m;
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            std :: swap(a, b);
        b -= a;
    } while (b != 0);
    return (a << shift);
}
