#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  vector<string> v;
  v.emplace_back("0"); v.emplace_back("1");
  for(int i=2;i<1<<n;i<<=1){
    for(int j=i-1;j>=0;--j) v.emplace_back(v[j]);
    for(int j=0;j<i;++j) v[j]="0"+v[j];
    for(int j=i;j<2*i;++j) v[j]="1"+v[j];
  }
  for(auto&s:v)cout<<s<<'\n';
  return 0;
}

