#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>v;
void dfs(int k,int i,int j){
  if(!k) return;
  dfs(k-1,i,6-i-j);
  v.emplace_back(i,j);
  dfs(k-1,6-i-j,j);
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  dfs(n,1,3);
  cout<<v.size()<<'\n';
  for(auto&p:v) cout<<p.first<<" "<<p.second<<'\n';
  return 0;
}

