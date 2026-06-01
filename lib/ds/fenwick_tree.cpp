#include "template.hpp"

const int N = 0;

lli ft[N + 1];
void upd(int i0, int v) {
	for (int i = i0 + 1; i <= N; i += i & -i)
		ft[i] += v;
}
int get(int i0) {
	lli r = 0;
	for (int i = i0; i; i -= i & -i)
		r += ft[i];
	return r;
}
int get_sum(int i0, int i1) { return get(i1) - get(i0); }
