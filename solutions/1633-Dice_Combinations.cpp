#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int dp[n+1]; dp[0]=1;
  for(int i=1;i<=n;++i){
    dp[i]=0;
    for(int j=1;j<7&&i>=j;++j)
      dp[i]+=dp[i-j],dp[i]%=m;
  }
  cout<<dp[n]<<'\n';
  return 0;
}

