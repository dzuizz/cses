#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  int ans=0;
  for(int i=0,run=0;i<(int)s.size();++i){
    if(i&&s[i]==s[i-1]) ++run;
    else run=1;
    ans=max(ans,run);
  }
  cout<<ans<<'\n';
  return 0;
}

