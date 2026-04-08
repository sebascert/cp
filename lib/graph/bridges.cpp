#include "template.hpp"

const int N = 0 + 1;
int n, m;
vector<int> g[N];

int depth[N];
int dfs(int u, int p) {
	depth[u] = depth[p] + 1;

	int dp = 0;
	for (int v : g[u]) {
		if (v == p)
			continue;

		if (!depth[v]) { // span edge
			dp += dfs(v, u);
		} else if (depth[v] < depth[u]) { // back edge
			dp++;
		} else { // back edge in reverse
			dp--;
		}
	}

	if (p != n && dp == 0)
		; // bridge

	return dp;
}

void bridges() {
	fill(depth, depth + N, 0);
	dfs(0, n);
}
