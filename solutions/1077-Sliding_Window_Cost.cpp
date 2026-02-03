#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  multiset<int> lf,rg;
  int ls=0,rs=0;
  auto add=[&](multiset<int>&ms,int&sm,int x){
    ms.emplace(x);
    sm+=x;
  };
  auto rem=[&](multiset<int>&ms,int&sm,int x){
    ms.erase(ms.find(x));
    sm-=x;
  };
  auto bal=[&](){
    while(rg.size()>lf.size()) add(lf,ls,*rg.begin()),rem(rg,rs,*rg.begin());
    while(lf.size()-rg.size()>1) add(rg,rs,*lf.rbegin()),rem(lf,ls,*lf.rbegin());
  };
  int a[n]; for(int i=0,res=0;i<n;++i){
    cin>>a[i];
    if(lf.size() && *lf.rbegin()<a[i]) add(rg,rs,a[i]);
    else add(lf,ls,a[i]);
    if(i>=k){
      if(lf.size() && *lf.rbegin()<a[i-k]) rem(rg,rs,a[i-k]);
      else rem(lf,ls,a[i-k]);
    }
    bal();
    if(i>=k-1){
      int m=*lf.rbegin();
      cout<<m*lf.size()-ls+rs-m*rg.size()<<" ";
    }
  }
  cout<<'\n';
  return 0;
}

