#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int ans=0;
  for(int i=0,p=0;i<n;++i){
    int x; cin>>x;
    if(i) ans+=max(0ll,p-x);
    p=max(p,x);
  }
  cout<<ans<<'\n';
  return 0;
}

