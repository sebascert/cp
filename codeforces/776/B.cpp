#include <bits/stdc++.h>

using namespace std;

#define IOP                                                                              \
    ios_base::sync_with_stdio(0); /* false */                                            \
    cin.tie(0);                   /* NULL */                                             \
    cout.tie(0);                  /* NULL */

#define SETUP IOP;

#define fora(i, a, b) for(size_t i = (a); (i) < (b); ++i) // [a -> b)

typedef size_t sz;
typedef long long lli;

void solve(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for(sz i = 2; i * i <= n; i++) {
        if(sieve[i]) {
            for(sz j = i * i; j <= n; j += i) sieve[j] = false;
        }
    }
    cout << (n < 4 ? 1 : 2) << endl;
    fora(i, 2, n + 1) {
        cout << (sieve[i] ? 1 : 2) << " ";
    }
}

int main() {
    SETUP;

    int n;
    cin >> n;
    solve(n + 1);
}
