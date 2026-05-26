#include "template.hpp"

struct Trie {
	struct Node {
		int c;
		map<char, int> e;
	};
	int n;
	vector<Node> t;
	Trie() : n(1), t(1) {}
	void insert(string &s) {
		int i = 0;
		for (int c : s) {
			t[i].c++; // count in prefix
			if (!t[i].e[c]) {
				t[i].e[c] = n++;
				t.emplace_back();
			}
			i = t[i].e[c];
		}
		t[i].c++; // count at end
	}
};
