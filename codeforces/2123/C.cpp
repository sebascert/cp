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
#define fora(i, a, b) for(size_t(i) = (a); (i) < (b); i++)   // [a -> b)
#define ford(i, a, b) for(size_t(i) = (a) + 1; --(i) > (b);) // (b <- a]

// math utils
#define INF(T, s) numeric_limits<T>::s()
#define mid(l, r) (l) + ((l) + (r)) / 2

#define btlc(p) ((p) * 2)     // binary tree buf left child
#define btrc(p) ((p) * 2 + 1) // binary tree buf right child

// type utils
#define alias_t(T, A)                                                                    \
    typedef T A;                                                                         \
    const T POSINF = INF(T, max);                                                        \
    const T NEGINF = INF(T, min);                                                        \
    typedef vector<T> vec;

typedef long long lli;
typedef long double ld;

alias_t(lli, num);

template <typename N> struct STree { // segment tree for sum and minimum
    struct Node {
        N mn, mx;                                                        // @ state
        Node(N mn = INF(N, max), N mx = INF(N, min)) : mn(mn), mx(mx) {} // @ identities
        Node op(Node other) { // @ operations, this operates over other
            other.mn = min(mn, other.mn);
            other.mx = max(mx, other.mx);
            return other;
        }
    };
    size_t n;
    vector<Node> tree;
    STree(vector<N> arr) : n(sz(arr)), tree(n * 2) { // O(N)
        Node buf;
        fora(i, 0, n) tree[i + n] =
            Node(arr[i], arr[i]); // @ identity elem to node arr[i]*#identites
        ford(i, n - 1, 0) tree[i] = tree[btlc(i)].op(tree[btrc(i)]);
    }
    void set(size_t idx, N val) { // O(logN)
        for(tree[idx += n] = val; idx /= 2;)
            tree[idx] = tree[btlc(idx)].op(tree[btrc(idx) | 1]);
    }
    Node query(size_t idx) { return tree[idx + n]; } // O(1)
    Node query(size_t left, size_t right) {          // O(logN) [left, right)
        Node resl, resr;
        for(left += n, right += n; left < right; left /= 2, right /= 2) {
            if(left & 1) resl = resl.op(tree[left++]);
            if(right & 1) resr = tree[--right].op(resr);
        }
        return resl.op(resr);
    }
};

int main(int argc, char *argv[]) {
    SETUP;
    size_t t;
    cin >> t;

    size_t n;
    vec nums;
    fora(i, 0, t) {
        cin >> n;
        nums.resize(n);
        fora(i, 0, n) cin >> nums[i];
        STree<num> mm_tree(nums);

        num num;
        bool reducible;
        for(size_t i = 0; i < n; i++) {
            num = mm_tree.query(i).mn;
            if(num == mm_tree.query(0, i + 1).mn) {
                reducible = num == mm_tree.query(i, n).mn ||
                            num == mm_tree.query(i, n).mx ||
                            num < mm_tree.query(i + 1, n).mx;
            } else if(num == mm_tree.query(i, n).mx) {
                reducible = num == mm_tree.query(0, i + 1).mn ||
                            num == mm_tree.query(0, i + 1).mx ||
                            num > mm_tree.query(0, i).mn;
            } else
                reducible = false;
            cout << (reducible ? "1" : "0");
        }
        cout << endl;
    }
    return 0;
}
