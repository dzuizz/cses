#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void upd(int *fw,int x,int v){
  for(++x;x<=n;x+=(x&-x)) fw[x]+=v;
}
int sum(int *fw,int x){
  int res=0;
  for(++x;x>0;x-=(x&-x)) res+=fw[x];
  return res;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n;
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i];
  }
  int fw[n+5]{};
  for(int i=0;i<n;++i){
    int x; cin>>x; --x;
    int l=0,r=n-1,m;
    while(l<r){
      m=(l+r)>>1;
      int cnt=sum(fw,m);
      if(cnt+x <= m) r=m;
      else l=m+1;
    }
    cout<<a[l]<<" ";
    upd(fw,l,1);
  }
  cout<<'\n';
  return 0;
}

