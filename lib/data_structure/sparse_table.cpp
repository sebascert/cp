#include "template.hpp"

const int N = 0, logN = log2(N) + 2;
int n;

#define oper min
int st[logN][N];
void st_init(int *a) {
	fore(i, 0, n) st[0][i] = a[i];
	fore(k, 1, logN) fore(i, 0, n - (1 << k) + 1) st[k][i] =
	    oper(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}
int st_query(int s, int e) { //[s,e)
	int k = 31 - __builtin_clz(e - s);
	return oper(st[k][s], st[k][e - (1 << k)]);
}
