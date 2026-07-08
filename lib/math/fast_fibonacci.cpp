#include "template.hpp"

const int mod = 1e9 + 7;

ii fib(lli n) {
	if (n == 0)
		return {0, 1};
	auto [f0, f1] = fib(n / 2);
	int x = f0 * (2 * f1 - f0 + mod) % mod, y = (f0 * f0 + f1 * f1) % mod;
	return n & 1 ? (ii){y, (x + y) % mod} : (ii){x, y};
}
