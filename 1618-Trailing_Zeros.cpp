#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int ans=0;
  for(int i=5;i<=n;i*=5)
    for(int j=i;j<=n;j+=i) ++ans;
  cout<<ans<<'\n';
  return 0;
}

