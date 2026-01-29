#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,x; cin>>n>>x;
  map<int,int>mp;
  int a=0,b=0;
  for(int i=1;i<=n;++i){
    int e; cin>>e;
    if(mp[x-e]) a=i,b=mp[x-e];
    mp[e]=i;
  }
  if(a+b) cout<<a<<" "<<b<<'\n';
  else cout<<"IMPOSSIBLE\n";
  return 0;
}

