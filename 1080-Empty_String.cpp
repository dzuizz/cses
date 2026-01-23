#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;

inline int add(int a,int b){
  a+=b;
  if(a>=M) a-=M;
  return a;
}

inline int mul(int a,int b){
  return a*b%M;
}

int binpow(int a,int b){
  int res=1;
  while(b){
    if(b&1) res=mul(res,a);
    a=mul(a,a),b>>=1;
  }
  return res;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  int n=s.size();
  if(n&1){
    cout<<"0\n";
    return 0;
  }

  int f[n/2+1]; f[0]=1;
  for(int i=1;i<=n/2;++i) f[i]=mul(f[i-1],i);
  int invf[n/2+1]; invf[0]=1;
  for(int i=1;i<=n/2;++i) invf[i]=binpow(f[i],M-2);
  auto C=[&](const int&N,const int&K){
    return mul(f[N],mul(invf[K],invf[N-K]));
  };

  int dp[n][n]{};
  for(int i=0;i<n-1;++i) if(s[i]==s[i+1]){
    dp[i][i+1]=1;
  }
  for(int l=4;l<=n;l+=2){
    for(int i=0;i<=n-l;++i){
      int j=i+l-1;
      for(int k=i+1;k<=j;k+=2) if(s[i]==s[k]){
        dp[i][j]=add(dp[i][j],
            mul((i+1<k?dp[i+1][k-1]:1),
            mul((k<j?dp[k+1][j]:1),
            C(l/2,(j-k)/2))));
      }
    }
  }
  //for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<dp[i][j]<<" "; cout<<'\n'; }
  cout<<dp[0][n-1]<<'\n';
  return 0;
}


