#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,e; cin>>n;
  int ans=n*(n+1)/2;
  for(int _=1;_<n;++_){
    cin>>e;
    ans-=e;
  }
  cout<<ans<<'\n';
  return 0;
}

