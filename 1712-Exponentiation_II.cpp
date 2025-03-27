#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD=1e9+7;
int binpow(int&a,int b,int m){
  int ret=1;
  while(b){
    if(b&1)ret=ret*a%m;
    a=a*a%m,b>>=1;
  }
  return ret;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int a,b,c; cin>>a>>b>>c;
    cout<<binpow(a,binpow(b,c,MOD-1),MOD)<<'\n';
  }
  return 0;
}

