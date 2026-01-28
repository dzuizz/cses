#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,x; cin>>n>>x;
  int p[n],c[n];
  for(int i=0;i<n;++i) cin>>p[i];
  for(int i=0;i<n;++i) cin>>c[i];
  int dp[x+1]{};
  dp[0]=0;
  for(int i=0;i<n;++i){
    for(int j=x;j>=p[i];--j){
      dp[j]=max(dp[j],dp[j-p[i]]+c[i]);
    }
  }
  cout<<*max_element(dp,dp+x+1)<<'\n';
  return 0;
}

