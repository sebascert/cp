#include "template.hpp"

const int N = 100;
int n;
vector<int> g[N];

struct edge {
	int u, v, comp;
	bool bridge;
};
vector<edge> e;
void add_edge(int u, int v) {
	g[u].pb(e.size());
	g[v].pb(e.size());
	e.pb((edge){u, v, -1, false});
}
int D[N], B[N], T;
int nbc;
int art[N];
stack<int> st;
void dfs(int u, int pe) {
	B[u] = D[u] = T++;
	for (int ne : g[u])
		if (ne != pe) {
			int v = e[ne].u ^ e[ne].v ^ u;
			if (D[v] < 0) {
				st.push(ne);
				dfs(v, ne);
				if (B[v] > D[u])
					e[ne].bridge = true;
				if (B[v] >= D[u]) {
					art[u]++;
					int last;
					do {
						last = st.top();
						st.pop();
						e[last].comp = nbc;
					} while (last != ne);
					nbc++;
				}
				B[u] = min(B[u], B[v]);
			} else if (D[v] < D[u])
				st.push(ne), B[u] = min(B[u], D[v]);
		}
}

void doit() {
	memset(D, -1, sizeof(D));
	memset(art, 0, sizeof(art));
	nbc = T = 0;
	fore(i, 0, n) if (D[i] < 0) dfs(i, -1), art[i]--;
}
