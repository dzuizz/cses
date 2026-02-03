#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  map<int,int> mp;
  int a[n]; for(int i=0,res=0;i<n;++i){
    cin>>a[i];
    if(++mp[a[i]]==1) ++res;
    if(i>=k) if(!--mp[a[i-k]]) --res;
    if(i>=k-1) cout<<res<<" ";
  }
  cout<<'\n';
  return 0;
}

