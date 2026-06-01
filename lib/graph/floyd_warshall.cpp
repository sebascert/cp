#include "template.hpp"

const int N = 0;

int n;
lli g[N][N];
void floyd() {
	fore(k, 0, n) fore(i, 0, n) if (g[i][k] < INF)
	    fore(j, 0, n) if (g[k][j] < INF) g[i][j] =
		min(g[i][j], g[i][k] + g[k][j]);
}

bool in_neg_cycle(int u) { return g[u][u] < 0; }
bool has_neg_cycle(int u, int v) {
	fore(i, 0,
	     n) if (g[u][i] < INF && g[i][v] < INF && g[i][i] < 0) return true;
	return false;
}
