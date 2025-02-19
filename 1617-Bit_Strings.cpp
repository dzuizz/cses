#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a=2,ans=1;
  while(n){
    if(n&1) ans=ans*a%m;
    a=a*a%m,n>>=1;
  }
  cout<<ans<<'\n';
  return 0;
}

