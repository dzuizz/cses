#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  map<int,int> mp;
  priority_queue<pair<int,int>>pq;
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i];
    pq.emplace(++mp[a[i]],-a[i]);
    if(i>=k) --mp[a[i-k]];
    if(i>=k-1){
      while(mp[-pq.top().second]<pq.top().first) pq.pop();
      cout<<-pq.top().second<<" ";
    }
  }
  cout<<'\n';
  return 0;
}


