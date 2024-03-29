#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5+5;
vector<int> adj[MAXN];

pair<int, int> dfs(int cur, int prev) { // (dist, node)
    pair<int, int> ret = {0, cur};
    for (int &x: adj[cur]) {
        if (x == prev) continue;
        pair<int, int> tmp = dfs(x, cur);
        tmp.first++;
        ret = max(ret, tmp);
    }
    return ret;
}

signed main() {
    int n; cin >> n;
    
    for (int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> d1 = dfs(1, 0);
    pair<int, int> d2 = dfs(d1.second, 0);

    cout << d2.first << '\n';
}