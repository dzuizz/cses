#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,a,b; cin>>n>>a>>b;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  int res=-3e18,ps[n+1]{};
  for(int i=1;i<=n;++i){
    cin>>ps[i];
    ps[i]+=ps[i-1];
    while(pq.size()&&i-pq.top().second>b) pq.pop();
    if(i>=a){
      pq.emplace(ps[i-a],i-a);
      res=max(res,ps[i]-pq.top().first);
    }
  }
  cout<<res<<'\n';
  return 0;
}
