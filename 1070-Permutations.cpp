#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  if(n==2||n==3) cout<<"NO SOLUTION\n";
  else{
    for(int i=2;i<=n;i+=2) cout<<i<<" ";
    for(int i=1;i<=n;i+=2) cout<<i<<" ";
    cout<<'\n';
  }
  return 0;
}

