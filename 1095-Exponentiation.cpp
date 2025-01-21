#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
int binpow(int a,int b){
  int ret=1;
  while(b){
    if(b&1)ret=ret*a%m;
    a*=a,a%=m,b>>=1;
  }
  return ret;
}
signed main() {
  int n; cin>>n;
  for(int i=0;i<n;++i){
    int a,b; cin>>a>>b;
    cout<<binpow(a,b)<<'\n';
  }
}

