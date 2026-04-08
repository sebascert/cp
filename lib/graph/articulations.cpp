#include "template.hpp"

const int N = 0 + 1;
int n, m;
vector<int> g[N];

int depth[N], art[N];
int dfs(int u, int p) {
	int dp = depth[u] = depth[p] + 1;
	for (int v : g[u]) {
		if (v == p)
			continue;

		if (!depth[v]) { // span edge
			dp = min(dp, dfs(v, u));
		} else if (depth[v] < depth[u]) { // back edge
			dp = min(dp, depth[v]);
		}
	}

	art[p] += dp <= depth[p];

	return dp;
}

void articulations() {
	fill(depth, depth + N, 0);
	fill(art, art + N, false);
	dfs(0, n);
	art[0]--;

	fore(u, 0, n) {
		if (art[u])
			; // articulation
	}
}
