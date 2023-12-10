#include <iostream>
int n, i, j, k, l, r, mid, pos;
long long int v[100000], dp[100000], aux[100000], ans[100000];
int main() {
    std :: cin >> n;
    for (i = 1; i <= n; ++ i)
        std :: cin >> v[i];
    dp[++ k] = v[1];
    aux[k] = k;
    for (i = 2; i <= n; ++ i)
        if (v[i] > dp[k]) {
            dp[++ k] = v[i];
            aux[i] = k;
        }
        else {
            l = 1;
            r = k;
            pos = k + 1;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (dp[mid] > v[i]) {
                    pos = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            dp[pos] = v[i];
            aux[i] = pos;
        }
    j = n;
    for (i = k; i != 0; -- i) {
        while (aux[j] != i)
            -- j;
        ans[i] = j;
    }
    std :: cout << k << '\n';
    for (i = 1; i <= k; ++ i)
        std :: cout << v[ans[i]] << ' ';
    return 0;
}
