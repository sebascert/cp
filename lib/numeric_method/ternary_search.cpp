#include "template.hpp"

const ld eps = 1e-9;

ld f(ld x);

ld tsearch(ld l, ld r) {
	while (r - l > eps) {
		ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2))
			l = m1;
		else
			r = m2;
	}
	return f(l);
}

lli tsearch(lli l, lli r) {
	while (r - l >= 3) {
		lli m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2))
			l = m1;
		else
			r = m2;
	}
	lli x = r, fx = f(r);
	fore(y, l, r) {
		ld fy = f(y);
		if (fx < fy)
			x = y, fx = fy;
	}
	return x;
}
