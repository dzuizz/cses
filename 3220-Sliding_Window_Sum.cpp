#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int arr[n];
  int a,b,c; cin>>arr[0]>>a>>b>>c;
  for(int i=1,x=arr[0];i<n;++i) arr[i]=(x*a+b)%c,x=arr[i];
  int res=0,run=0;
  for(int i=0;i<k;++i) run+=arr[i];
  res^=run;
  for(int i=k;i<n;++i){
    run+=arr[i]-arr[i-k];
    res^=run;
  }
  cout<<res<<'\n';
  return 0;
}

