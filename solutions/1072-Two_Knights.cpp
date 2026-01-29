#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  for(int k=1;k<=n;++k)
    cout<<(k*k*(k*k-1)/2-4*(k-1)*(k-2))<<'\n';
  return 0;
}

