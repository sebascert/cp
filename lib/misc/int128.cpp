#include "template.hpp"

typedef __int128_t lll;

string to_string(lll x) {
	if (x == 0)
		return "0";

	int sign = x < 0 ? -1 : 1;
	x *= sign;

	string s;
	while (x > 0) {
		s.pb(x % 10);
		x /= 10;
	}

	if (sign < 0)
		s.pb('-');

	reverse(all(s));
	return s;
}
