#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a[8]; for(auto&x:a) cin>>x;
  int p[8],ans=0; iota(p,p+8,0);
  do{
    bool f=1;
    for(int i=0;i<8&&f;++i) f=(a[i][p[i]]=='.');
    if(!f) continue;
    map<int,bool> x,y;
    for(int i=0;i<8;++i) x[i+p[i]]=1,y[i-p[i]]=1;
    if(x.size()<8||y.size()<8) continue;
    ++ans;
  }while(next_permutation(p,p+8));
  cout<<ans<<'\n';
  return 0;
}

