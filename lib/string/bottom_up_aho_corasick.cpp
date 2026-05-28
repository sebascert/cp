#include "template.hpp"

const int C = 26, A = 'a';
struct vertex {
	vi next, go, leaf;
	char pch;
	int p, link, nl;
	vertex(int p = -1, char pch = -1)
	    : next(C, -1), go(C, 0), pch(pch), p(p), link(-1), nl(-1) {}
};
vector<vertex> t;
void aho_init() {
	t.clear();
	t.pb(vertex());
}
void add(string s, int id) {
	int v = 0;
	for (auto x : s) {
		int c = x - A;
		if (t[v].next[c] == -1) {
			t[v].next[c] = t[v].go[c] = sz(t);
			t.pb(vertex(v, c));
		}
		v = t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, int c) { return t[v].go[c - A]; }
void BFS() {
	queue<int> q;
	q.push(0);
	t[0].link = t[0].nl = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		fore(c, 0, C) {
			if (t[x].next[c] == -1)
				continue;
			int y = t[x].next[c];
			t[y].link = x ? t[t[x].link].go[c] : 0;
			int link = t[y].link;
			t[y].nl = sz(t[link].leaf) ? link : t[link].nl;
			for (int i = 0; i < C; i++)
				if (t[y].next[i] == -1)
					t[y].go[i] = t[link].go[i];
			q.push(y);
		}
	}
}
