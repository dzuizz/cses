#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  pair<int,int>a[n];
  for(auto&p:a)
    cin>>p.second>>p.first;
  sort(a,a+n);
  int ans=0,p=0,i=0;
  while(i<n){
    ++ans,p=a[i++].first;
    while(i<n&&a[i].second<p) ++i;
  }
  cout<<ans<<'\n';
  return 0;
}

