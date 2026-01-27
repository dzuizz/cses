#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,res=0; cin>>n;
  while(n){
    int tn=n/10,v=n%10;
    while(tn) v=max(v,tn%10),tn/=10;
    n-=v,++res;
  }
  cout<<res<<'\n';
  return 0;
}

