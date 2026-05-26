#include "template.hpp"

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;

lli n, a, b, c, q, t, x, y, k;
// const lli MAXN=1e5;
// const lli MOD = 998244353;

typedef long long tf;
typedef vector<tf> poly;
const tf MOD = 998244353, RT = 5; // COMPROBAR! //2305843009255636993

const double pi = acos(-1.0);
const int MAXN = 1 << 23;
int R[MAXN + 9];

int mulmod(lli a, lli b) { return a * b % MOD; }
int addmod(int a, int b) {
	int r = a + b;
	if (r >= MOD)
		r -= MOD;
	return r;
}
int submod(int a, int b) {
	int r = a - b;
	if (r < 0)
		r += MOD;
	return r;
}
int pm(lli a, lli e) {
	int r = 1;
	while (e) {
		if (e & 1)
			r = mulmod(r, a);
		e >>= 1;
		a = mulmod(a, a);
	}
	return r;
}
int inv(int a) { return pm(a, MOD - 2); }

struct CD {
	tf x;
	CD(tf x) : x(x) {}
	CD() {}
};
CD operator*(const CD &a, const CD &b) { return CD(mulmod(a.x, b.x)); }
CD operator+(const CD &a, const CD &b) { return CD(addmod(a.x, b.x)); }
CD operator-(const CD &a, const CD &b) { return CD(submod(a.x, b.x)); }
vector<tf> rts(MAXN + 9, -1);
CD root(int n, bool inv) {
	tf r = rts[n] < 0 ? rts[n] = pm(RT, (MOD - 1) / n) : rts[n];
	return CD(inv ? pm(r, MOD - 2) : r);
}

CD cp1[MAXN + 9], cp2[MAXN + 9];
void dft(CD *a, int n, bool inv) {
	fore(i, 0, n) if (R[i] < i) swap(a[R[i]], a[i]);
	for (int m = 2; m <= n; m *= 2) {
		// double z=2*pi/m*(inv?-1:1); // FFT
		// CD wi=CD(cos(z),sin(z)); // FFT
		CD wi = root(m, inv); // NTT
		for (int j = 0; j < n; j += m) {
			CD w(1);
			for (int k = j, k2 = j + m / 2; k2 < j + m; k++, k2++) {
				CD u = a[k];
				CD v = a[k2] * w;
				a[k] = u + v;
				a[k2] = u - v;
				w = w * wi;
			}
		}
	}
	// if(inv)fore(i,0,n)a[i]/=n; // FFT
	if (inv) {		      // NTT
		CD z(pm(n, MOD - 2)); // pm: modular exponentiation
		fore(i, 0, n) a[i] = a[i] * z;
	}
}

poly multiply(poly &p1, poly &p2) {
	int n = p1.size() + p2.size() + 1;
	int m = 1, cnt = 0;
	while (m <= n)
		m += m, cnt++;
	fore(i, 0, m) {
		R[i] = 0;
		fore(j, 0, cnt) R[i] = (R[i] << 1) | ((i >> j) & 1);
	}
	fore(i, 0, m) cp1[i] = 0, cp2[i] = 0;
	fore(i, 0, p1.size()) cp1[i] = p1[i];
	fore(i, 0, p2.size()) cp2[i] = p2[i];
	dft(cp1, m, false);
	dft(cp2, m, false);
	fore(i, 0, m) cp1[i] = cp1[i] * cp2[i];
	dft(cp1, m, true);
	poly res;
	n -= 2;
	// fore(i,0,n)res.pb((ll)floor(cp1[i].real()+0.5)); // FFT
	fore(i, 0, n) res.pb(cp1[i].x); // NTT
	return res;
}
