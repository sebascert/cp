#include "template.hpp"

const int N = 0 + 1;
int lp[N];
vector<int> pr;

void sieve() {
	fore(i, 2, N) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}

		for (int j = 0; i * pr[j] < N; j++) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i])
				break;
		}
	}
}
