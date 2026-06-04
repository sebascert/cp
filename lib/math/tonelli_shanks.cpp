#include "template.hpp"

lli binexp(lli a, lli b, lli m) {
	a %= m;
	lli x = 1;
	while (b) {
		if (b & 1)
			x = x * a % m;
		a = a * a % m;
		b /= 2;
	}
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
lli rnd(lli a, lli b) { return uniform_int_distribution<lli>(a, b)(rng); }
lli legendre(lli a, lli p) {
	if (a % p == 0)
		return 0;
	if (p == 2)
		return 1;
	return binexp(a, (p - 1) / 2, p);
}
lli tonelli_shanks(lli n, lli p) {
	// assert(legendre(n, p) == 1);
	// assert(p % 4 == 1);
	if (p == 2)
		return 1;
	lli s = __builtin_ctzll(p - 1), q = (p - 1) >> s, z = rnd(1, p - 1);
	if (s == 1)
		return binexp(n, (p + 1) / 4, p);
	while (legendre(z, p) != p - 1)
		z = rnd(1, p - 1);
	lli c = binexp(z, q, p), r = binexp(n, (q + 1) / 2, p),
	    t = binexp(n, q, p), m = s;
	while (t != 1) {
		lli i = 1, ts = t * t % p;
		while (ts != 1)
			i++, ts = ts * ts % p;
		lli b = c;
		for (int tt = 0; tt < m - i - 1; tt++)
			b = b * b % p;
		r = r * b % p;
		c = b * b % p;
		t = t * c % p;
		m = i;
	}
	return min(r, p - r);
}
