#include <iostream>
uint32_t longIncrArr(uint32_t n, int64_t v[], uint32_t ans[]) {
	int64_t dp[n], aux[n];
	uint32_t k = 1;
    dp[k] = v[1];
    aux[k] = k;
    uint32_t i, l, r, mid, pos;
    for (i = 2; i <= n; ++ i) {
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
    }
    uint32_t j = n;
    for (i = k; i > 0; -- i) {
        while (aux[j] != i)
            -- j;
        ans[i] = j;
    }
    return k;
}
int main() {
	std :: ios_base :: sync_with_stdio(false);
	std :: cin.tie(nullptr);
	uint32_t n, i;
    std :: cin >> n;
    int64_t v[n];
    for (i = 1; i <= n; ++ i)
        std :: cin >> v[i];
	uint32_t ans[n], len = longIncrArr(n, v, ans);
    std :: cout << len << '\n';
    for (i = 1; i <= len; ++ i)
		std :: cout << ans[i] << ' ';
    return 0;
}
