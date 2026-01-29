#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,x; cin>>n>>x;
  int a[n]; for(int i=0;i<n;++i) cin>>a[i];
  int dp[x+1]{}; dp[0]=1;
  for(int j=0;j<n;++j){
    for(int i=1;i<=x;++i){
      if(a[j]<=i){
        dp[i]+=dp[i-a[j]],
        dp[i]%=M;
      }
    }
  }
  cout<<dp[x]%M<<'\n';
  return 0;
}

