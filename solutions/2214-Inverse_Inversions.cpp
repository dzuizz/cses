#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int res[n],l=1,r=n;
  for(int i=0;i<n;++i){
    if(k>=n-i-1) res[i]=r--,k-=n-i-1;
    else res[i]=l++;
  }
  for(auto&x:res) cout<<x<<" "; cout<<'\n';
  return 0;
}

