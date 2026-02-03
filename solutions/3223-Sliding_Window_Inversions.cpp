#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXA=1e9;
struct node{
  int l,r,m,v;
  node *lf,*rg;
  node(int _l,int _r):l(_l),r(_r),m((_l+_r)>>1),v(0){
    lf=nullptr,rg=nullptr;
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
  int qry(int x,int y){
    if(x<=l && r<=y) return v;
    if(x>r || y<l) return 0;
    return (lf?lf->qry(x,y):0)+(rg?rg->qry(x,y):0);
  }
}*root;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int a[n]; for(int i=0;i<n;++i)
    cin>>a[i];
  root=new node(1,MAXA);
  int res=0;
  for(int i=0;i<n;++i){
    res+=root->qry(a[i]+1,MAXA);
    root->upd(a[i],1);
    if(i>=k) res-=root->qry(1,a[i-k]-1),root->upd(a[i-k],-1);
    if(i>=k-1) cout<<res<<" ";
  }
  cout<<'\n';
  return 0;
}

