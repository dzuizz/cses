#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
vector<int> adj[N];
int sz[N];

void dfs(int i) {
  sz[i] = 0;
  for (auto &x : adj[i]) {
    dfs(x);
    sz[i] += sz[x] + 1;
  }
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  for (int i = 2; i <= N; ++i) {
    int e; cin >> e;
    adj[e].emplace_back(i);
  }
   
  dfs(1);
  for(int i = 1; i <= N; ++i)
    cout << sz[i] << " ";
  cout << '\n';
  return 0;
}

