#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,x; cin>>n>>x;
  vector<int> dp(x+1,3e18);
  dp[0]=0;
  for(int i=0;i<n;++i){
    int e; cin>>e;
    for(int j=e;j<=x;++j)
      dp[j]=min(dp[j],dp[j-e]+1);
  }
  cout<<(dp[x]==3e18?-1:dp[x])<<'\n';
  return 0;
}

