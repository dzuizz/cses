#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  sort(s.begin(),s.end());
  map<string,bool> mp;
  do{
    mp[s]=1;
  }while(next_permutation(s.begin(),s.end()));
  cout<<mp.size()<<'\n';
  for(auto&p:mp)
    cout<<p.first<<'\n';
  return 0;
}

