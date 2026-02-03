#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  multiset<int> lf,rg;
  int a[n]; for(int i=0,res=0;i<n;++i){
    cin>>a[i];
    if(lf.size() && *lf.rbegin()<a[i]) rg.emplace(a[i]);
    else lf.emplace(a[i]);
    while(rg.size()>lf.size()) lf.emplace(*rg.begin()),rg.erase(rg.begin());
    while(lf.size()-rg.size()>1) rg.emplace(*lf.rbegin()),lf.erase(lf.find(*lf.rbegin()));
    if(i>=k){
      if(lf.size() && *lf.rbegin()<a[i-k]) rg.erase(rg.find(a[i-k]));
      else lf.erase(lf.find(a[i-k]));
      while(rg.size()>lf.size()) lf.emplace(*rg.begin()),rg.erase(rg.begin());
      while(lf.size()-rg.size()>1) rg.emplace(*lf.rbegin()),lf.erase(lf.find(*lf.rbegin()));
    }
    if(i>=k-1) cout<<*lf.rbegin()<<" ";
  }
  cout<<'\n';
  return 0;
}

