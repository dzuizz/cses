#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+5;
int ft[N];
int sum(int x){
  int res=0;
  for(;x>0;x-=(x&-x)) res+=ft[x];
  return res;
}
void upd(int x,int v){ for(;x<N;x+=(x&-x)) ft[x]+=v; }
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int x[n]; for(int i=1;i<=n;++i){
    cin>>x[i];
    upd(i,x[i]);
    upd(i+1,-x[i]);
  }
  while(q--){
    int t; cin>>t;
    if(t==1){
      int a,b,u; cin>>a>>b>>u;
      upd(a,u);
      upd(b+1,-u);
    }else{
      int k; cin>>k;
      cout<<sum(k)<<'\n';
    }
  }
  return 0;
}

