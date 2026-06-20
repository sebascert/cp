#include "template.hpp"

bool f(lli x);
lli bsearch(lli l, lli log) {
	lli x = l;
	ford(b, log, 0) {
		lli y = x + (1ll << b);
		if (f(y))
			x = y;
	}

	return x;
}
