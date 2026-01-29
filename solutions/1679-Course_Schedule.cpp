#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> topo_sort(int n, vector<vector<int>> &adj) {
    vector<int> in(n, 0), res;
    for (auto &v : adj) for (int u : v) in[u]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop(); res.push_back(v);
        for (int u : adj[v]) if (--in[u] == 0) q.push(u);
    }
    return res.size() == n ? res : vector<int>();
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  vector<vector<int>> adj(n);
  for(int i=0;i<m;++i){
    int a,b; cin>>a>>b;
    --a,--b;
    adj[a].emplace_back(b);
  }
  vector<int> topo_order=topo_sort(n,adj);
  if(topo_order.size()){
    for(auto&x:topo_order) cout<<x+1<<" ";
    cout<<'\n';
  }else{
    cout<<"IMPOSSIBLE\n";
  }
  return 0;
}

