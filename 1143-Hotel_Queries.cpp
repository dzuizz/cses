#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  int l,r,v,m;
  node *lf,*rg;
  node(int _l,int _r,int a[]): l(_l),r(_r),m((_l+_r)>>1),v(0){
    if(l==r) v=a[l];
    else
      lf=new node(l,m,a),
      rg=new node(m+1,r,a),
      v=max(lf->v,rg->v);
  }
  int qry(int x){
    if(l==r){
      return l;
    }
    return (lf->v<x?rg->qry(x):lf->qry(x));
  }
  void upd(int x,int cv){
    if(l==r){
      v=cv;
      return;
    }
    (x<=m?lf:rg)->upd(x,cv);
    v=max(lf->v,rg->v);
  }
}*root;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int a[n];
  for(int i=0;i<n;++i) cin>>a[i];
  root=new node(0,n-1,a);
  while(m--){
    int x; cin>>x;
    if(x>root->v) cout<<"0 ";
    else{
      int u=root->qry(x);
      a[u]-=x;
      root->upd(u,a[u]);
      cout<<u+1<<" ";
    }
  }
  cout<<'\n';
  return 0;
}

