#include <bits/stdc++.h>

using namespace std;

#define IOP                                                                              \
    ios_base::sync_with_stdio(0); /* false */                                            \
    cin.tie(0);                   /* NULL */                                             \
    cout.tie(0);                  /* NULL */

#define SETUP IOP;

#define fora(i, a, b) for(size_t i = (a); (i) < (b); ++i) // [a -> b)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n + 1), diff(n + 2);
    map<int, int> freq;
    fora(i, 0, n) {
        cin >> a[i];
        freq[a[i]]++;
    }
    fora(i, 0, n + 1) {
        diff[freq[i]]++;
        diff[n - i + 1]--;
        if(!freq[i]) break;
    }
    fora(k, 0, n + 1) {
        ans[k] = (k ? ans[k - 1] : 0) + diff[k];
        cout << ans[k] << (k != n ? ' ' : '\n');
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
