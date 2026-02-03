#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  vector<int> adj[n];
  for(int i=0,u,v;i<m;++i)
    cin>>u>>v,
    adj[--u].emplace_back(--v),
    adj[v].emplace_back(u);
  int di[n+1]; memset(di,0x3f,sizeof di);
  di[0]=0;
  queue<int> q; q.emplace(0);
  while(q.size()){
    int u=q.front(); q.pop();
    for(auto&v:adj[u]) if(di[v]==di[n]){
      q.emplace(v);
      di[v]=di[u]+1;
    }
  }
  if(di[n-1]==di[n]) cout<<"IMPOSSIBLE\n";
  else{
    vector<int> v; v.emplace_back(n-1);
    for(int i=di[n-1]-1;i>=0;--i){
      int nx;
      for(auto&u:adj[v.back()])
        if(di[u]==i) nx=u;
      v.emplace_back(nx);
    }
    cout<<di[n-1]+1<<'\n';
    for(int i=(int)v.size()-1;i>=0;--i) cout<<v[i]+1<<" "; cout<<'\n';
  }
  return 0;
}

