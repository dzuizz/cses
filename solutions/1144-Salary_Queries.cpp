#include<bits/stdc++.h>
using namespace std;
struct node{
  int l,r,m,v;
  node *lf,*rg;
  node(int _l,int _r):l(_l),r(_r),m((_l+_r)>>1),v(0) {
    lf=nullptr,
    rg=nullptr;
  }
  void upd(int x,int d){
    if(l==r){
      v+=d;
      return;
    }
    if(x<=m){ if(!lf) lf=new node(l,m);
    }else if(!rg) rg=new node(m+1,r);
    (x<=m?lf:rg)->upd(x,d);
    v=(lf?lf->v:0)+(rg?rg->v:0);
  }
  int qry(int a,int b){
    if(a<=l && r<=b) return v;
    if(a>r || b<l) return 0;
    return (lf?lf->qry(a,b):0)+(rg?rg->qry(a,b):0);
  }
}*root;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int p[n]; for(int i=0;i<n;++i){
    cin>>p[i];
  }
  root=new node(1,1e9);
  for(int i=0;i<n;++i) root->upd(p[i],1);
  while(q--){
    char c; int a,b;
    cin>>c>>a>>b;
    if(c=='?') cout<<root->qry(a,b)<<'\n';
    else{
      root->upd(p[--a],-1);
      p[a]=b;
      root->upd(p[a],1);
    }
  }
  return 0;
}

