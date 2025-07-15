#include <bits/stdc++.h>

using namespace std;

#define IOP                                                                              \
    ios_base::sync_with_stdio(0); /* false */                                            \
    cin.tie(0);                   /* NULL */                                             \
    cout.tie(0);                  /* NULL */

#define SETUP IOP;

#define iter(v) v.begin(), v.end()

#define fora(i, a, b) for(size_t i = (a); (i) < (b); ++i) // [a -> b)

typedef size_t sz;
typedef long long lli;

void solve(int n) {
    vector<sz> sieve(n + 1, 0);

    fora(i, 2, n + 1) {
        if(sieve[i] != 0) continue;
        for(sz j = i * 2; j <= n; j += i) {
            sieve[j]++;
        }
    }

    sz ap = 0;
    fora(i, 6, n + 1) {
        if(sieve[i] == 2) ap++;
    }

    cout << ap << endl;
}

int main() {
    SETUP;

    int n;
    cin >> n;
    solve(n);
}
