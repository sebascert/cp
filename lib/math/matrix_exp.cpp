#include "template.hpp"

typedef vector<vector<lli>> Matrix;
const lli mod = 1e9 + 7;

Matrix iden(int n) {
	Matrix r(n, vector<lli>(n));
	fore(i, 0, n) r[i][i] = 1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n = sz(a), m = sz(b[0]), z = sz(a[0]);
	Matrix r(n, vector<lli>(m));
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
