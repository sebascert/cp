#include "template.hpp"

struct Segtree {
#define mid ((l + r) / 2)
#define left(u) (u + 1)
#define right(u) (u + ((mid - l + 1) << 1))
	struct Node {
		lli s;
		Node(lli s = 0) : s(s) {}
		Node operator+(const Node &n) { return Node(s + n.s); }
	};
	int n;
	vector<Node> st;
	Segtree(int n) : n(n), st(2 * n) {}
	void update(int u, int l, int r, int kth, lli val) {
		if (l == r) {
			st[u] = Node(val); // assignment query
			return;
		}
		if (kth <= mid)
			update(left(u), l, mid, kth, val);
		else
			update(right(u), mid + 1, r, kth, val);
		st[u] = st[left(u)] + st[right(u)];
	}
	Node query(int u, int l, int r, int ll, int rr) {
		if (l > r || r < ll || l > rr)
			return Node();
		if (ll <= l && r <= rr)
			return st[u];
		return query(left(u), l, mid, ll, rr) +
		       query(right(u), mid + 1, r, ll, rr);
	}
	void update(int i, lli x) { update(0, 0, n - 1, i, x); }
	lli query(int l, int r) { return query(0, 0, n - 1, l, r).s; }
};

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
		st[i += n] = Node(x); // assignment query
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
