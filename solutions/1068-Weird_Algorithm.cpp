#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  while(n>1){
    cout<<n<<" ";
    n=n&1?n*3+1:n>>1;
  }
  cout<<"1\n";
  return 0;
}

