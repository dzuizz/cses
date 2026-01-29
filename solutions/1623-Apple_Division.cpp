#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,ans=INT64_MAX; cin>>n;
  int a[n]; for(auto&x:a) cin>>x;
  for(int msk=0;msk<(1<<n);++msk){
    int v[2]{};
    for(int i=0;i<n;++i) v[msk>>i&1]+=a[i];
    ans=min(ans,abs(v[0]-v[1]));
  }
  cout<<ans<<'\n';
  return 0;
}

