#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int a[n+2],p[n+2],ans=1; p[0]=0,p[n+1]=n+1;
  for(int i=1;i<=n;++i)
    cin>>a[i],p[a[i]]=i;
  for(int i=1;i<=n;++i)
    if(p[i]<p[i-1]) ++ans;
  while(q--){
    int r,s; cin>>r>>s;
    int x=a[r],y=a[s];
    if(x>y) swap(x,y);
    ans-=(p[x-1]>p[x])+(p[x]>p[x+1])
        +(p[y-1]>p[y])+(p[y]>p[y+1]);
    if(y==x+1) ans+=(p[x]>p[y]);
    swap(a[r],a[s]); swap(p[x],p[y]);
    ans+=(p[x-1]>p[x])+(p[x]>p[x+1])
        +(p[y-1]>p[y])+(p[y]>p[y+1]);
    if(y==x+1) ans-=(p[x]>p[y]);
    cout<<ans<<'\n';
  }
  return 0;
}

