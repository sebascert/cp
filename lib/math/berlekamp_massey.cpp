#include "template.hpp"

const lli mod = 1e9 + 7;

lli binexp(lli a, lli b) {
	a %= mod;
	lli x = 1;
	while (b > 0) {
		if (b & 1)
			x = x * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return x;
}

vector<int> BM(vector<int> x) {
	vector<int> ls, cur;
	int lf = -1, ld = -1;
	for (int i = 0; i < (int)(x.size()); ++i) {
		long long t = 0;
		for (int j = 0; j < (int)(cur.size()); ++j)
			t = (t + x[i - j - 1] * (long long)cur[j]) % mod;
		if ((t - x[i]) % mod == 0)
			continue;
		if (!(int)cur.size()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		long long k = -(x[i] - t) * binexp(ld, mod - 2) % mod;
		vector<int> c(i - lf - 1);
		c.push_back(k);
		for (int j = 0; j < (int)(ls.size()); ++j)
			c.push_back(-ls[j] * k % mod);
		if ((int)c.size() < (int)(cur.size()))
			c.resize((int)(cur.size()));
		for (int j = 0; j < (int)(cur.size()); ++j)
			c[j] = (c[j] + cur[j]) % mod;
		if (i - lf + (int)(ls.size()) >= (int)(cur.size()))
			ls = cur, lf = i, ld = (t - x[i]) % mod;
		cur = c;
	}
	for (int i = 0; i < (int)(cur.size()); ++i)
		cur[i] = (cur[i] % mod + mod) % mod;
	return cur;
}

const int LOG = 50;
// init O(n^2log) query(n^2 logk)
// input: terms: first n term; trans: transition function; mod; LOG=mxlog of k
// output calc(k): kth term mod mod
// example: {1,1} {2,1} an=2*a_(n-1)+a_(n-2); calc(3)=3 calc(10007) = 71480733
struct LinearRec {
	typedef vector<int> vi;
	int n;
	vi terms, trans;
	vector<vi> bin;
	vi add(vi &a, vi &b) {
		vi res(n * 2 + 1);
		fore(i, 0, n + 1) fore(j, 0, n + 1) res[i + j] =
		    (res[i + j] * 1LL + (lli)a[i] * b[j]) % mod;
		for (int i = 2 * n; i > n; --i) {
			fore(j, 0, n) res[i - 1 - j] =
			    (res[i - 1 - j] * 1LL + (lli)res[i] * trans[j]) %
			    mod;
			res[i] = 0;
		}
		res.erase(res.begin() + n + 1, res.end());
		return res;
	}
	LinearRec(vi &terms, vi &trans) : terms(terms), trans(trans) {
		n = sz(trans);
		vi a(n + 1);
		a[1] = 1;
		bin.pb(a);
		fore(i, 1, LOG) bin.pb(add(bin[i - 1], bin[i - 1]));
	}
	int calc(int k) {
		vi a(n + 1);
		a[0] = 1;
		fore(i, 0, LOG) if ((k >> i) & 1) a = add(a, bin[i]);
		int ret = 0;
		fore(i, 0, n) ret = ((lli)ret + (lli)a[i + 1] * terms[i]) % mod;
		return ret;
	}
};
