#include "template.hpp"

struct IterativeSegtree {
	struct Node {
		lli s;
		Node(lli s = 0) : s(s) {}
		Node operator+(const Node &n) { return Node(s + n.s); }
	};
	int n;
	vector<Node> st;
	IterativeSegtree(int n) : n(n), st(2 * n) {}
	void build() { // copy original array to st [n,2*n)
		ford(i, n, 0) st[i] = st[i << 1] + st[i << 1 | 1];
	}
	void update(int i, lli x) {
		i += n;
		st[i] = Node(x); // assignment query
		for (; i > 1; i >>= 1)
			st[i >> 1] = st[i] + st[i ^ 1];
	}
	lli query(int l, int r) { // query on [l,r]
		Node ll, rr;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1)
				ll = ll + st[l++];
			if (r & 1)
				rr = st[--r] + rr;
		}
		return (ll + rr).s;
	}
};
