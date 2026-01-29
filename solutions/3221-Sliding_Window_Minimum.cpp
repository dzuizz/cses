#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int arr[n];
  int a,b,c; cin>>arr[0]>>a>>b>>c;
  for(int i=1,x=arr[0];i<n;++i){
    arr[i]=(x*a+b);
    if(arr[i]>=c) arr[i]%=c;
    x=arr[i];
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  int res=0;
  for(int i=0;i<k;++i) pq.emplace(arr[i],i);
  res^=pq.top().first;
  for(int i=k;i<n;++i){
    pq.emplace(arr[i],i);
    while(pq.top().second<=i-k) pq.pop();
    res^=pq.top().first;
  }
  cout<<res<<'\n';
  return 0;
}


