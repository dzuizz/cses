#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T, U, chash>;
template <class T, class U = null_type, class cmp = less<T>> using oset = tree<T, U, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
#define IO(NAME) cin.tie(0)->sync_with_stdio(0); if (fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), freopen(NAME ".out","w",stdout);  // Fast IO & File I/O

#define fi first
#define se second
#define int long long

void solve() {
    int n; cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << "NO\n";
        return;
    }

    vector<int> a, b;
    int target = sum / 2;
    for (int i=n; i>=1; i--) {
        if (target - i >= 0) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << "YES\n";
    cout << a.size() << '\n';
    for (int i : a) cout << i << ' ';
    cout << '\n';
    cout << b.size() << '\n';
    for (int i : b) cout << i << ' ';
    cout << '\n';
}

signed main() {
    IO(""); // File name here if needed

    int tc = 1;
    // cin >> tc;
    for (int t=1; t<=tc; t++) {
        // cout << "Case #" << t << '\n';
        solve();
    }
}
