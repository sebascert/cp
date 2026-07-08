#include "template.hpp"

const int N = 0 + 1, logN = log2(N) + 2;

int n;
vector<int> t[N];

int st[logN][N], d[N];
void dfs(int u, int p) {
	st[0][u] = p;
	d[u] = d[p] + 1;
	for (int v : t[u]) {
		if (v == p)
			continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (d[u] < d[v])
		swap(u, v);
	ford(k, logN, 0) {
		if (d[u] - (1 << k) >= d[v])
			u = st[k][u];
	}
	if (u == v)
		return u;
	ford(k, logN, 0) {
		if (st[k][u] != st[k][v])
			u = st[k][u], v = st[k][v];
	}
	return st[0][u];
}

void lca_init() {
	d[n] = 0;
	dfs(0, n);
	fore(k, 1, logN) fore(u, 0, n) st[k][u] =
	    st[k - 1][u] == n ? n : st[k - 1][st[k - 1][u]];
}
