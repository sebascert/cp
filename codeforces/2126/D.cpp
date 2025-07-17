#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define IOP                                                                              \
    ios_base::sync_with_stdio(0); /* false */                                            \
    cin.tie(0);                   /* NULL */                                             \
    cout.tie(0);                  /* NULL */

#define SETUP IOP;

// func like utils
#define perr(x) cerr << #x << " = " << (x) << endl
#define iter(v) v.begin(), v.end()

// code utils
#define fora(i, a, b) for(size_t i = (a); (i) < (b); ++i) // [a -> b)
#define ford(i, a, b) for(size_t i = (a); (i)-- > (b);)   // [b <- a)

// math utils
#define INF(T, s) numeric_limits<T>::s() // s: min | max
#define mid(l, r) ((l) + ((l) + (r)) / 2)

#define btlc(p) ((p) * 2)     // binary tree buf left child
#define btrc(p) ((p) * 2 + 1) // binary tree buf right child

// type utils
#define alias_t(T, A)                                                                    \
    typedef T A;                                                                         \
    const T POSINF = INF(T, max);                                                        \
    const T NEGINF = INF(T, min);                                                        \
    typedef vector<T> vec;

typedef size_t sz;
typedef long long lli;
typedef long double ld;

alias_t(long long, num);

struct casino {
    num l, r, real;
};

void solve(num n, vec &p, vec &s) {
    bool v = true;
    num inv = p[n - 1];
    fora(i, 0, n - 1) {
        if(gcd(p[i], s[i + 1]) == inv) continue;
        v = false;
        break;
    }
    cout << (v ? "YES" : "NO") << endl;
}

int main() {
    SETUP;

    sz t;
    cin >> t;
    while(t--) {
        sz n;
        cin >> n;
        vec p(n), s(n);
        fora(i, 0, n) cin >> p[i];
        fora(i, 0, n) cin >> s[i];
        solve(n, p, s);
    }
}
