#include "template.hpp"

lli binexp(lli a, lli b, lli m) {
	a %= m;
	lli x = 1;
	while (b > 0) {
		if (b & 1)
			x = x * a % m;
		b /= 2;
		a = a * a % m;
	}
	return x;
}
