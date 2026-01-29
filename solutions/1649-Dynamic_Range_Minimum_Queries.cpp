#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int SZ=447;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int x[n]; for(int i=0;i<n;++i) cin>>x[i];
  int m=(n+SZ-1)/SZ,mn[m]; memset(mn,0x3f,sizeof mn);
  for(int i=0;i<n;++i){
    int j=i/SZ;
    mn[j]=min(mn[j],x[i]);
  }
  return 0;
}

