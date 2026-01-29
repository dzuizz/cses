#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m,k; cin>>n>>m>>k;
  int a[n]; for(auto&x:a) cin>>x;
  int b[m]; for(auto&x:b) cin>>x;
  sort(a,a+n); sort(b,b+m);
  int ans=0,i=0;
  for(auto&x:a){
    while(i<m&&b[i]+k<x) ++i;
    if(i<m&&x-k<=b[i]&&b[i]<=x+k) ++ans,++i;
  }
  cout<<ans<<'\n';
  return 0;
}

