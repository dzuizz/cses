#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200005;
const int LOG=18;
vector<int> adj[MAXN];
int pa[MAXN][LOG], dep[MAXN];
void dfs(int i){
  for(auto&x:adj[i]){
    if(x==pa[i][0]) continue;
    pa[x][0]=i;
    dep[x]=dep[i]+1;
    dfs(x);
  }
}
int lca(int a,int b){
  if(dep[a]<dep[b]) swap(a,b);
  for(int j=LOG-1;j>=0;--j)
    if(dep[pa[a][j]]>=dep[b])
      a=pa[a][j];
  if(a==b) return a;
  for(int j=LOG-1;j>=0;--j)
    if(pa[a][j]!=pa[b][j])
      a=pa[a][j],b=pa[b][j];
  return pa[a][0];
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  for(int i=1;i<n;++i){
    int u,v; cin>>u>>v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  pa[1][0]=1;
  dfs(1);
  for(int j=0;j<LOG-1;++j)
    for(int i=1;i<=n;++i)
      pa[i][j+1]=pa[pa[i][j]][j];
  while(q--){
    int u,v; cin>>u>>v;
    cout<<dep[u]+dep[v]-2*dep[lca(u,v)]<<'\n';
  }
  return 0;
}
