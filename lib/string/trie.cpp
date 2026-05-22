#include "template.hpp"

const int lc = 'A', rc = 'Z';
struct Trie {
	struct Node {
		int c, e[rc - lc + 1];
		Node() : c(1) { memset(e, -1, sizeof(e)); }
	};
	int n;
	vector<Node> t;
	Trie() : n(1), t(1) {}
	void insert(string &s) {
		int i = 0;
		for (int c : s) {
			c -= lc;
			if (t[i].e[c] == -1) {
				t[i].e[c] = n++;
				t.emplace_back();
			}
			i = t[i].e[c];
		}
		t[i].c++;
	}
};
