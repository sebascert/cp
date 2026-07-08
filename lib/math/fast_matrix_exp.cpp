#include "template.hpp"

const lli mod = 1e9 + 7;

const int K = 0;
using Matrix = lli[K][K];
void iden(Matrix m) {
	memset(m, 0, sizeof(Matrix));
	fore(i, 0, K) m[i][i] = 1;
}
void mult(const Matrix a, const Matrix b, Matrix m) {
	Matrix c;
	memset(c, 0, sizeof(Matrix));
	fore(i, 0, K) fore(j, 0, K) fore(k, 0, K) c[i][j] =
	    (c[i][j] + (lli)a[i][k] * b[k][j]) % mod;
	memcpy(m, c, sizeof(Matrix));
}
void binexp(const Matrix m, lli b, Matrix c) {
	iden(c);
	Matrix a;
	memcpy(a, m, sizeof(Matrix));
	while (b) {
		if (b & 1)
			mult(a, c, c);
		mult(a, a, a);
		b /= 2;
	}
}
