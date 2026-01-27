#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n]; for(auto&x:a) cin>>x;
  sort(a,a+n);
  int x=a[n/2],res=0;
  for(int i=0;i<n;++i){
    res+=abs(a[i]-x);
  }
  cout<<res<<'\n';
  return 0;
}

