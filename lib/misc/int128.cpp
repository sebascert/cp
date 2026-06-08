#include "template.hpp"

typedef __int128 lll;
typedef unsigned __int128 ulll;

string to_string(lll x) {
	if (x == 0)
		return "0";

	bool neg = x < 0;
	ulll y = -(ulll)x;

	string s;
	while (x > 0) {
		s.pb('0' + y % 10);
		y /= 10;
	}

	if (neg)
		s.pb('-');

	reverse(all(s));
	return s;
}
