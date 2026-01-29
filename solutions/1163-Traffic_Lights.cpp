#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int x,n; cin>>x>>n;
  int a[n];
  for(int i=0;i<n;++i) cin>>a[i];
  map<int,bool> mp;
  map<int,int> c;
  mp[0]=1,mp[x]=1,c[x]=1;
  for(int i=0;i<n;++i){
    auto rg=mp.lower_bound(a[i]),lf=rg; --lf;
    if(!--c[rg->first-lf->first]) c.erase(rg->first-lf->first);
    ++c[rg->first-a[i]],++c[a[i]-lf->first];
    mp[a[i]]=1;
    cout<<c.rbegin()->first<<" ";
  }
  cout<<'\n';
  return 0;
}

