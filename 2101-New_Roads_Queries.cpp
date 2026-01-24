#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int LOG=20;

namespace dsu{
  vector<int> pa,sz;
  int n;
  void init(int _n){
    n=_n;
    pa=vector<int>(n); iota(pa.begin(),pa.end(),0);
    sz=vector<int>(n,1);
  }
  int f(int x){ return pa[x]==x?x:pa[x]=f(pa[x]); }
  bool m(int a,int b){
    int fa=f(a),fb=f(b);
    if(fa==fb) return 0;
    if(sz[fa]<sz[fb]) swap(fa,fb);
    pa[fb]=fa;
    sz[fa]+=sz[fb];
    return 1;
  }
};

namespace mst{
  vector<array<int,LOG>> pa,di;
  vector<int> dep;
  int n;
  void init(int _n){
    n=_n;
    pa=vector<array<int,LOG>>(n);
    di=vector<array<int,LOG>>(n);
    dep=vector<int>(n,-1);
    for(int i=0;i<n;++i){
      pa[i].fill(-1);
      di[i].fill(0);
    }
  }
  void dfs(vector<vector<pair<int,int>>>& g,int root){
    stack<int> st;
    st.emplace(root);
    while(st.size()){
      int u=st.top(); st.pop();
      for(auto&[w,v]:g[u]){
        if(v==pa[u][0]) continue;
        pa[v][0]=u;
        di[v][0]=w;
        dep[v]=dep[u]+1;
        st.emplace(v);
      }
    }
  }
  void pa_init(){
    for(int j=1;j<LOG;++j) for(int i=0;i<n;++i){
      int p=pa[i][j-1];
      pa[i][j]=pa[p][j-1];
      di[i][j]=max(di[i][j-1],di[p][j-1]);
    }
  }
  int lca(int a,int b){
    if(pa[a][LOG-1]!=pa[b][LOG-1]) return -1;
    if(dep[a]<dep[b]) swap(a,b);
    int d=dep[a]-dep[b];
    for(int i=0;i<LOG;++i) if(d>>i&1) a=pa[a][i];
    if(a==b) return a;
    for(int i=LOG-1;i>=0;--i) if(pa[a][i]!=pa[b][i]){
      a=pa[a][i],b=pa[b][i];
    }
    return pa[a][0];
  }
  int dis(int l,int k){
    int res=0;
    for(int i=0;i<LOG;++i){
      if(k>>i&1){
        res=max(res,di[l][i]);
        l=pa[l][i];
      }
    }
    return res;
  }
  int qry(int a,int b){
    int c=lca(a,b);
    if(c==-1) return -1;
    return max(dis(a,dep[a]-dep[c]),dis(b,dep[b]-dep[c]));
  }
};

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n,m,q; cin>>n>>m>>q;

  dsu::init(n);
  vector<vector<pair<int,int>>> g(n);
  for(int i=1;i<=m;++i){
    int a,b; cin>>a>>b; --a,--b;
    if(dsu::m(a,b)){
      g[a].emplace_back(i,b);
      g[b].emplace_back(i,a);
    }
  }

  mst::init(n);
  for(int i=0;i<n;++i){
    if(mst::dep[i]==-1){
      mst::pa[i][0]=i;
      mst::di[i][0]=0;
      mst::dep[i]=0;
      mst::dfs(g,i);
    }
  }
  mst::pa_init();

  while(q--){
    int a,b; cin>>a>>b; --a,--b;
    cout<<mst::qry(a,b)<<'\n';
  }
  return 0;
}

