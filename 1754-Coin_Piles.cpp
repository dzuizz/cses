#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int a,b; cin>>a>>b;
    if(a<b) swap(a,b);
    cout<<(a<=2*b&&(2*b-a)%3==0?"YES\n":"NO\n");
  }
  return 0;
}

