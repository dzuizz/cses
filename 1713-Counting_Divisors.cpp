#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[1000001];
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for(int i=2;i<1000001;++i) if(!p[i]) for(int j=i;j<1000001;j+=i)
    p[j]=i;
  int n; cin>>n;
  for(;n;--n){
    int x,ans=1; cin>>x;
    for(int i=0,res=1,k=p[x];k;++i,ans*=res,res=1,k=p[x]) while(x%k==0)
      x/=k,++res;
    cout<<ans<<'\n';
  }
  return 0;
}

