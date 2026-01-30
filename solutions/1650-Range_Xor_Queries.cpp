#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int a[n+1]; for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  int pxor[n+1]; pxor[0]=0;
  for(int i=1;i<=n;++i) pxor[i]=pxor[i-1]^a[i];
  while(q--){
    int a,b; cin>>a>>b;
    cout<<(pxor[b]^pxor[a-1])<<'\n';
  }
  return 0;
}

