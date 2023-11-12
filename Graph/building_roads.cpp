#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> lead;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int node) {
	vis[node] = true;

	for(auto child : adj[node]) {
		if(!vis[child]) {
			dfs(child);
		}
	}
}

int main() {
	int n, m;
	cin>>n>>m;
	int count = 0;

	vis.resize(n+1);
	adj.resize(n+1);

	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			count++;
			lead.push_back(i);
			dfs(i);
		}
	}

	cout<<count-1<<nl;
	if(count > 1) {
		int u = lead[0];
		int v;
		for(auto i=1; i<count; i++) {
			v = lead[i];
			cout<<u<<" "<<v<<nl;
			u = v;
		}
	}


	return 0;
}