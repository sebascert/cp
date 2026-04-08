#include "template.hpp"

const int N = 0;
int n;
vector<int> g[N];

// bool truth[N]; (2SAT)
// int nvar;
// int neg(int x) { return N - 1 - x; }

int lw[N], idx[N], qidx, cmp[N], qcmp;
stack<int> st;
void tjn(int u) {
	lw[u] = idx[u] = ++qidx;
	st.push(u);
	cmp[u] = -2;
	for (int v : g[u]) {
		if (!idx[v] || cmp[v] == -2) {
			if (!idx[v])
				tjn(v);
			lw[u] = min(lw[u], lw[v]);
		}
	}
	if (lw[u] == idx[u]) {
		int x;
		// int l = -1; (2SAT)
		do {
			x = st.top();
			st.pop();
			cmp[x] = qcmp;
			// if (min(x, neg(x)) < nvar) (2SAT)
			// 	l = x;
		} while (x != u);
		// if (l != -1) (2SAT)
		// 	truth[qcmp] = cmp[neg(l)] < 0;
		qcmp++;
	}
}
vector<int> crep;
void scc() {
	memset(idx, 0, sizeof(idx));
	qidx = 0;
	memset(cmp, -1, sizeof(cmp));
	qcmp = 0;
	fore(i, 0, n) if (!idx[i]) tjn(i);

	crep.resize(qcmp);
	fore(u, 0, n) crep[cmp[u]] = u;
}

// void addor(int a, int b) { g[neg(a)].pb(b), g[neg(b)].pb(a); } (2SAT)
// bool satisfy(int _nvar) {
// 	nvar = _nvar;
// 	n = N;
// 	scc();
// 	fore(i, 0, nvar) if (cmp[i] == cmp[neg(i)]) return false;
// 	return true;
// }
