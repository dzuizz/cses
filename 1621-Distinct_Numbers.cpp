#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  map<int,bool> mp;
  while(n--){
    int e; cin>>e;
    mp[e]=1;
  }
  cout<<(int)mp.size()<<'\n';
  return 0;
}
