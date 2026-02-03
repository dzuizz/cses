#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  map<int,int> mp;
  set<int> s;
  for(int i=0;i<=k;++i) s.emplace(i);
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i];
    if(++mp[a[i]]==1) s.erase(a[i]);
    if(i>=k) if(--mp[a[i-k]]==0) s.emplace(a[i-k]);
    if(i>=k-1){
      cout<<*s.begin()<<" ";
    }
  }
  cout<<'\n';
  return 0;
}

