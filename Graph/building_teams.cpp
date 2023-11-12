#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> color;
int n, m;

bool dfs(int u, int c, int par) {
	vis[u] = true;
	color[u] = c;

	for(auto v : adj[u]) {
		if(v == par) continue;
		if(color[v] == 0) {
			if(!dfs(v, (color[u]^3), u)) return false;
		}
		if(color[v] == color[u]) return false;
	}
	return true;
}

bool color_all() {
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			if(!dfs(i, 1, -1)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin>>n>>m;	

	adj.resize(n+1);
	vis.resize(n+1);
	color.resize(n+1);

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool ans = color_all();
	if(!ans) {
		cout<<"IMPOSSIBLE"<<nl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cout<<color[i]<<" ";
	}



	return 0;
}


// we will keep track of parents
// if the element exist in that ds, we will transfer 
// it to the other ds
// ================
// keeping track of parent
// bipartite graph problem
// check if there is a contradiction