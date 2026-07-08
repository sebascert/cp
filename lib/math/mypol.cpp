#include "template.hpp"

struct pol {
	vi term;
	int dl, dr;
	void print() {
		fore(i, 0, sz(term)) {
			if (term[i])
				cerr << term[i] << "*x^" << dl - i << " ";
		}
		cerr << endl;
	}
	pol operator*(const pol &o) {
		int ndl = dl + o.dl, ndr = dr + o.dr;
		pol n = {vi(ndl - ndr + 1), ndl, ndr};

		fore(i, 0, sz(term)) fore(j, 0, sz(o.term)) n.term[i + j] +=
		    term[i] * o.term[j];
		return n;
	}
};
