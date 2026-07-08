#include "template.hpp"

vector<int> longest_common_prefix(string &s, vector<int> &sa) {
	int n = sz(s), L = 0;
	vector<int> lcp(n), plcp(n), phi(n);
	phi[sa[0]] = -1;
	fore(i, 1, n) phi[sa[i]] = sa[i - 1];
	fore(i, 0, n) {
		if (phi[i] < 0) {
			plcp[i] = 0;
			continue;
		}
		while (s[i + L] == s[phi[i] + L])
			L++;
		plcp[i] = L;
		L = max(L - 1, 0);
	}
	fore(i, 0, n) lcp[i] = plcp[sa[i]];
	// LCP(i,j) = min(lcp[i+1] ... lcp[j])
	return lcp; // lcp[i] = LCP(sa[i-1],sa[i])
}
