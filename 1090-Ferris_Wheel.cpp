#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,x; cin>>n>>x;
  int a[n]; for(auto&e:a) cin>>e;
  sort(a,a+n);
  int ans=0;
  for(int i=0,j=n-1;i<=j;++i,--j){
    while(i<=j&&a[i]+a[j]>x) --j,++ans;
    if(i<=j) ++ans;
  }
  cout<<ans<<'\n';
  return 0;
}

