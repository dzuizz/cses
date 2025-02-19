#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int x,y; cin>>x>>y;
    cout<<(x>y?x&1?(x-1)*(x-1)+y:x*x-y+1:y&1?y*y-x+1:(y-1)*(y-1)+x)<<'\n';
  }
  return 0;
}

