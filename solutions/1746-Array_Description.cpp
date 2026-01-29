#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int a[n]; for(auto&x:a) cin>>x;
  int dp[n][m+2]{};
  if(a[0]==0) for(int j=1;j<=m;++j) dp[0][j]=1;
  else dp[0][a[0]]=1;
  for(int i=1;i<n;++i){
    if(a[i]==0) for(int j=1;j<=m;++j){
      dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%M;
    }else dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%M;
  }
  int ans=0;
  for(int j=1;j<=m;++j) ans+=dp[n-1][j],ans%=M;
  cout<<ans<<'\n';
  return 0;
}

