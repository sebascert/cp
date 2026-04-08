#include "template.hpp"

const int N = 0;
int n;
vector<int> g[N];

// sort source to sink, for sink to source flip every edge
vector<int> tsort() {
	vector<int> r;
	priority_queue<int> q;
	vector<int> d(2 * n, 0);
	fore(i, 0, n) fore(j, 0, g[i].size()) d[g[i][j]]++;
	fore(i, 0, n) if (!d[i]) q.push(-i);
	while (!q.empty()) {
		int x = -q.top();
		q.pop();
		r.pb(x);
		fore(i, 0, g[x].size()) {
			d[g[x][i]]--;
			if (!d[g[x][i]])
				q.push(-g[x][i]);
		}
	}
	return r;
}
