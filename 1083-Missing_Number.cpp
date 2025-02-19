#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis[200000];
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  bool vis[n+1]; memset(vis, 0, sizeof(vis));
  for(int i=1;i<n;++i){
    int x; cin>>x;
    vis[--x]=1;
  }
  for(int i=0;i<n;++i) if(!vis[i])
    cout<<i+1<<'\n';
  return 0;
}

