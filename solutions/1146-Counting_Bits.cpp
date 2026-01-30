#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,ans=0; cin>>n;
  for(int k=1;k<=n;k<<=1){
    ans+=(n+1)/(k<<1)*k;
    ans+=max((n+1)%(k<<1)-k,0ll);
  }
  cout<<ans<<'\n';
  return 0;
}

