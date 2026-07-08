#include "template.hpp"

using R = double;
using U = uint64_t;

bool f(R x);

const U SBIT = ((U)1 << (sizeof(U) * 8 - 1));
U encode(R x) {
	U u;
	memcpy(&u, &x, sizeof(U));
	return (u & SBIT) ? ~u : u ^ SBIT;
}
R decode(U u) {
	R x;
	u = (u & SBIT) ? u ^ SBIT : ~u;
	memcpy(&x, &u, sizeof(x));
	return x;
}
R rsearch(R l, R r) {
	// assert(sizeof(R) == sizeof(U));
	U ll = encode(l), rr = encode(r);
	while (ll < rr) {
		U m = ll + (rr - ll) / 2;
		f(decode(m)) ? rr = m : ll = m + 1;
	}
	return decode(ll);
}

R prsearch(R l, R r) {
#define conv(x, y) memcpy(&y, &x, sizeof(U))
	// assert(sizeof(R) == sizeof(U));
	// assert(l > 0 && r > 0);
	R x;
	U ll, rr, m;
	conv(l, ll), conv(r, rr);
	while (ll < rr) {
		m = ll + (rr - ll) / 2;
		conv(m, x);
		f(x) ? rr = m : ll = m + 1;
	}
	conv(rr, x);
	return x;
}
