#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  string g[n];
  for(auto&x:g) cin>>x;
  int dp[n][n]{}; dp[0][0]=(g[0][0]=='.');
  g[0][0]='s';
  for(int i=0;i<n;++i) for(int j=0;j<n;++j){
    if(g[i][j]=='.') dp[i][j]=((i?dp[i-1][j]:0)+(j?dp[i][j-1]:0))%M;
  }
  cout<<dp[n-1][n-1]<<'\n';
  return 0;
}

