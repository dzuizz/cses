#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  map<int,int>mp;
  while(n--){
    int x; cin>>x;
    ++mp[-x];
  }
  while(m--){
    int x; cin>>x;
    auto it=mp.lower_bound(-x);
    if(it==mp.end()) cout<<"-1\n";
    else{
      cout<<-it->first<<'\n';
      if(!--it->second) mp.erase(it);
    }
  }
  return 0;
}

