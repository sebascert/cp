#include "template.hpp"

struct DSU {
	vector<int> pr, rank;
	stack<pair<int, int>> what;
	DSU(int n) : pr(n), rank(n, 1) { iota(all(pr), 0); }
	int find(int u) { return pr[u] == u ? u : pr[u] = find(pr[u]); }
	void unite(int u, int v) {
		u = find(u), v = find(v);
		if (u != v) {
			if (rank[u] < rank[v])
				swap(u, v);
			rank[u] += rank[v];
			pr[v] = u;
			what.push({u, v});
		} else
			what.push({-1, -1});
	}
	pair<int, int> rollback() {
		pair<int, int> last = what.top();
		what.pop();
		int u = last.f, v = last.s;
		if (u != -1) {
			rank[u] -= rank[v];
			pr[v] = v;
		}
		return last;
	}
};
