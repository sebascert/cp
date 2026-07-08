#include "template.hpp"

const lli mod = 1e9 + 7;

typedef vector<vi> Matrix;
#define nmat(n, m) vector<vi>(n, vi(m))
Matrix iden(int n) {
	Matrix r = nmat(n, n);
	fore(i, 0, n) r[i][i] = 1;
	return r;
}
Matrix operator*(const Matrix &a, const Matrix &b) {
	int n = sz(a), m = sz(b[0]), z = sz(a[0]);
	Matrix r = nmat(n, m);
	fore(i, 0, n) fore(j, 0, m) fore(k, 0, z) r[i][j] += a[i][k] * b[k][j],
	    r[i][j] %= mod;
	return r;
}
Matrix binexp(Matrix a, lli b) {
	Matrix x = iden(sz(a));
	while (b) {
		if (b & 1)
			x = x * a;
		a = a * a;
		b /= 2;
	}
	return x;
}
