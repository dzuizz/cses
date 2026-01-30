#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int SZ=447,INF=3e18;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int x[n]; for(int i=0;i<n;++i) cin>>x[i];
  int m=(n+SZ-1)/SZ,mn[m]; fill(mn,mn+m,INF);
  for(int i=0;i<n;++i){
    int j=i/SZ;
    mn[j]=min(mn[j],x[i]);
  }
  while(q--){
    int t,a,b; cin>>t>>a>>b;
    if(t==1){
      int j=--a/SZ;
      x[a]=b,mn[j]=INF;
      for(int i=j*SZ;i<min(n,(j+1)*SZ);++i){
        mn[j]=min(mn[j],x[i]);
      }
    }else{
      int res=INF,i=--a/SZ,j=--b/SZ;
      if(i==j) for(int k=a;k<=b;++k) res=min(res,x[k]);
      else{
        for(int k=a;k<(i+1)*SZ;++k) res=min(res,x[k]);
        for(int k=i+1;k<j;++k) res=min(res,mn[k]);
        for(int k=j*SZ;k<=b;++k) res=min(res,x[k]);
      }
      cout<<res<<'\n';
    }
  }
  return 0;
}

