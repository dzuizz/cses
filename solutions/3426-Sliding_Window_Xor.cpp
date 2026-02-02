#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int x,a,b,c; cin>>x>>a>>b>>c;
  queue<int> q;
  int ans=0;
  for(int i=0,run=x;i<n;run^=(x=(a*x+b)%c),++i){
    q.emplace(x);
    if((int)q.size()>k) run^=q.front(),q.pop();
    if((int)q.size()==k) ans^=run;
  }
  cout<<ans<<'\n';
  return 0;
}

