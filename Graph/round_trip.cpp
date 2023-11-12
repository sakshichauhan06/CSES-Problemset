#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> par;
int sv, ev;
int n, m;

bool dfs(int u, int p) {
	vis[u] = true;
	par[u] = p;

	for(auto v : adj[u]) {
		if(v == p) continue;
		if(vis[v]) {
			sv = v;
			ev = u;
			return true;
		}
		if(!vis[v]) {
			if(dfs(v, u)) return true;
		}
	}

	return false;
}

bool visit_all() {
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			if(dfs(i, -1)) return true;
		}
	}
	return false;
}

int main() {

	cin>>n>>m;

	adj.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);

	// for(int i=0; i<=n; i++) {
	// 	adj[i].resize(m);
	// }

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// we are calling dfs through here
	if(!visit_all()) {
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

	int tv = ev;
	vector<int> ans;
	ans.push_back(ev);

	while(tv != sv) {
		ans.push_back(par[tv]);
		tv = par[tv];
	}

	ans.push_back(ev);

	cout<<ans.size()<<nl;
	for(auto x : ans) {
		cout<<x<<" ";
	}

	return 0;
}