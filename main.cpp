#include <iostream>
#pragma GCC target("abm", "bmi", "bmi2", "popcnt", "lzcnt")
unsigned long long int gcd(unsigned long long int a, unsigned long long b) {
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
int main() {
    return 0;
}
