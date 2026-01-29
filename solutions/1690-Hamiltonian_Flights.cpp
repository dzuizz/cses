#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  vector<int> p[n];
  for(int i=0;i<m;++i){
    int u,v; cin>>u>>v;
    p[--v].emplace_back(--u);
  }
  int dp[1<<n][n]; memset(dp,0,sizeof dp);
  dp[1][0]=1;
  for(int msk=0;msk<(1<<n);++msk){
    if((msk>>(n-1)&1)&&msk!=((1<<n)-1)) continue;
    for(int i=1;i<n;++i) if(msk>>i&1){
      int p_msk=msk^(1<<i);
      for(int&j:p[i]){
        dp[msk][i]=(dp[msk][i]+dp[p_msk][j])%M;
      }
    }
  }
  cout<<dp[(1<<n)-1][n-1]<<'\n';
  return 0;
}

