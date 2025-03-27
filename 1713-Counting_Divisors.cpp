#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  for(int i=0;i<n;++i){
    int x; cin>>x;
    int ans=1;
    for(int k=2;k*k<=x;++k){
      int res=1;
      while(x%k==0)
        x/=k,++res;
      ans*=res;
    }
    if(x>1) ans*=2;
    cout<<ans<<'\n';
  }
  return 0;
}

