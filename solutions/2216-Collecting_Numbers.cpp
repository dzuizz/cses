#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int p[n],ans=1; for(int i=0,x;i<n;++i)
    cin>>x,p[--x]=i;
  for(int i=1;i<n;++i)
    if(p[i]<p[i-1]) ++ans;
  cout<<ans<<'\n';
  return 0;
}

