#include <bits/stdc++.h>

using namespace std;

#define IOP                                                                              \
    ios_base::sync_with_stdio(0); /* false */                                            \
    cin.tie(0);                   /* NULL */                                             \
    cout.tie(0);                  /* NULL */                                             \
    cerr.tie(0);                  /* NULL */

#define SETUP IOP;

// func like utils
#define sz(x) std::size(x)
#define perr(x) cerr << #x << " = " << (x) << endl

// code utils
#define fora(i, a, b) for(size_t i = (a); (i) < (b); ++i) // [a -> b)
#define ford(i, a, b) for(size_t i = (a); (i)-- > (b);)   // [b <- a)

int main(int argc, char *argv[]) {
    SETUP;

    size_t t;
    cin >> t;

    fora(i, 0, t) {
        char c;
        size_t n, k, zeros = 0;

        cin >> n >> k;
        fora(i, 0, n) cin >> c, zeros += c == '0';

        bool alice = n <= k + zeros || k > n / 2;
        cout << (alice ? "alice" : "bob") << endl;
    }
}
