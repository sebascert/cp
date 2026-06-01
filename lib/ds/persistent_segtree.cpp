#include "template.hpp"

const lli NEUT = 0;
#define oper(a, b) (a + b)
struct Segtree {
	vi st, L, R;
	int n, rt;
	Segtree(int n) : st(1, NEUT), L(1, 0), R(1, 0), n(n), rt(0) {}
	int new_node(lli v, int l = 0, int r = 0) {
		int ks = sz(st);
		st.pb(v);
		L.pb(l);
		R.pb(r);
		return ks;
	}
	int upd(int k, int s, int e, int p, lli v) {
		int ks = new_node(st[k], L[k], R[k]);
		if (s + 1 == e) {
			st[ks] = v;
			return ks;
		}
		int m = (s + e) / 2, ps;
		if (p < m)
			ps = upd(L[ks], s, m, p, v), L[ks] = ps;
		else
			ps = upd(R[ks], m, e, p, v), R[ks] = ps;
		st[ks] = oper(st[L[ks]], st[R[ks]]);
		return ks;
	}
	lli query(int k, int s, int e, int a, int b) {
		if (e <= a || b <= s)
			return NEUT;
		if (a <= s && e <= b)
			return st[k];
		int m = (s + e) / 2;
		return oper(query(L[k], s, m, a, b), query(R[k], m, e, a, b));
	}
	int upd(int k, int p, lli v) { return rt = upd(k, 0, n, p, v); }
	int upd(int p, lli v) { return upd(rt, p, v); } // update on last root;
	lli query(int k, int l, int r) { return query(k, 0, n, l, r); } //[l,r)
};
