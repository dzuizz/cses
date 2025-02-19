#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  if((n*(n+1)/2)&1) cout<<"NO\n";
  else{
    vector<int> a,b;
    int x=n*(n+1)/4;
    for(int i=n;i>=1;--i){
      if(x>=i){
        a.emplace_back(i);
        x-=i;
      }else b.emplace_back(i);
    }
    cout<<"YES\n";
    cout<<(int)a.size()<<'\n';
    for(auto&x:a) cout<<x<<" ";
    cout<<'\n';
    cout<<(int)b.size()<<'\n';
    for(auto&x:b) cout<<x<<" ";
    cout<<'\n';
  }
  return 0;
}

