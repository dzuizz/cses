#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[100005];
bool vis[100005],cycle_hellyea;
int col[100005];
stack<int> st;
void dfs(int i){
	vis[i] = 1;
	for(auto&x:adj[i]){
		if(vis[x]) continue;
		dfs(x);
	}
	st.emplace(i);
}
bool dfs_cycle(int i){
	col[i]=1;
	for(auto&x:adj[i]){
		if(col[x]==0){
			if(dfs_cycle(x)) return 1;
		}else if(col[x]==1){
			cycle_hellyea=1;
			return 1;
		}
	}
	col[i]=2;
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b; cin>>a>>b;
		adj[a].emplace_back(b);
	}
	for(int i=1;i<=n;++i){
		if(col[i]==0&&dfs_cycle(i))
			break;
	}
	if(cycle_hellyea){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		dfs(i);
	}
	while(st.size()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<'\n';
	return 0;
}
