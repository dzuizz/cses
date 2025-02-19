#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  int cnt[26]{};
  for(auto&c:s) ++cnt[c-'A'];
  int o=0;
  for(auto&x:cnt) o+=x&1;
  if(o>1) cout<<"NO SOLUTION\n";
  else{
    string ans="";
    for(int i=0;i<26;++i) if(cnt[i]&1^1) for(int j=0;j<cnt[i]>>1;++j)
      ans+=(char)('A'+i);
    cout<<ans;
    for(int i=0;i<26;++i) if(cnt[i]&1) for(int j=0;j<cnt[i];++j)
      cout<<(char)('A'+i);
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
  }
  return 0;
}

