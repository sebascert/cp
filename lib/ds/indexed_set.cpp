#include "template.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, typename V>
using itree =
    tree<T, V, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using iset = itree<T, null_type>;

// Usage
// find_by_order(k)
// order_of_key(x)
