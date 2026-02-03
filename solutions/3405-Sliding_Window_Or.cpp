#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k,x,a,b,c; cin>>n>>k>>x>>a>>b>>c;
  int po[n],so[n],i=1; for(po[0]=x,so[0]=x;i<n;++i)
    po[i]=(po[i-1]*a+b)%c,so[i]=po[i];
  for(int l=0,r=k-1;l<n;l+=k,r+=k,r=min(r,n-1)){
    for(i=l+1;i<=r;++i) po[i]|=po[i-1];
    for(i=r-1;i>=l;--i) so[i]|=so[i+1];
  }
  int ans=0;
  for(i=0;i<=n-k;++i)
    ans^=(so[i]|po[i+k-1]);
  cout<<ans<<'\n';
  return 0;
}

