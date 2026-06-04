#include "template.hpp"

struct DSU {
	int c = 0;
	map<lli, lli> uf;
	lli find(lli u) {
		if (!uf.count(u)) {
			uf[u] = -1;
			c++;
		}
		if (uf[u] < 0)
			return u;
		uf[u] = find(uf[u]);
		return uf[u];
	}
	void join(lli u, lli v) {
		u = find(u), v = find(v);
		if (u == v)
			return;
		if (uf[u] > uf[v])
			swap(u, v);
		uf[u] += uf[v];
		uf[v] = u;
		c--;
	}
};
