#include <iostream>
#include <map>
const uint16_t MaxFact = 20;
uint64_t fact[MaxFact + 1];
void precomputeFact() {
	uint64_t i;
	fact[0] = fact[1] = 1;
	for (i = 2; i <= MaxFact; ++ i)
		fact[i] = fact[i - 1] * i;
}
void getNthPerm(uint16_t len, uint64_t v[], uint64_t n, uint64_t ans[]) {
	precomputeFact();
	std :: map <uint64_t, uint64_t> fr;
	uint16_t i;
	for (i = 0; i < len; ++ i)
		++ fr[v[i]];
	uint64_t div = 1;
	std :: map <uint64_t, uint64_t> :: iterator j;
	for (j = fr.begin(); j != fr.end(); ++ j)
		div *= fact[j -> second];
	uint64_t passedPerm = 0, add;
	for (i = 0; i < len; ++ i) {
		add = 0;
		for (j = fr.begin(); j != fr.end() and passedPerm + add < n; ++ j)
			add += fact[len - i - 1] / (div / (j -> second));
		-- j;
		add -= fact[len - i - 1] / (div / (j -> second));
		passedPerm += add;
		div /= j -> second;
		ans[i] = j -> first;
		-- fr[j -> first];
		if (fr[j -> first] == 0)
			fr.erase(j -> first);
	}
}
int main() {
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(nullptr);
	uint16_t len, i;
	std :: cin >> len;
	uint64_t v[len];
	for (i = 0; i < len; ++ i)
		std :: cin >> v[i];
	uint64_t n, ans[len];
	std :: cin >> n;
	getNthPerm(len, v, n, ans);
	for (i = 0; i < len; ++ i)
		std :: cout << ans[i] << ' ';
    return 0;
}
