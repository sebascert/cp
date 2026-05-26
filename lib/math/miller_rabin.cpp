#include "template.hpp"

typedef unsigned long long ull;
using u128 = __uint128_t;

ull binexp(ull a, ull b, ull m) {
	a %= m;
	ull x = 1;
	while (b) {
		if (b & 1)
			x = (u128)x * a % m;
		a = (u128)a * a % m;
		b >>= 1;
	}
	return x;
}

bool check_composite(ull n, ull a, ull d, int s) {
	ull x = binexp(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
};

const int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller_rabin(ull n) {
	if (n < 4)
		return n == 2 || n == 3;
	if (~n & 1)
		return false;
	int r = 0;
	ull d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}
	fore(i, 0, sizeof(base) / sizeof(int)) {
		int a = base[i];
		if (n == (ull)a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}

	return true;
}
