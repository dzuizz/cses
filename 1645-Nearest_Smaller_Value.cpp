#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n+1]; a[0]=0;
  stack<int> st; st.emplace(0);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    while(a[st.top()]>=a[i]) st.pop();
    cout<<st.top()<<" ";
    st.emplace(i);
  }
  cout<<'\n';
  return 0;
}

