#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> par;

void bfs() {
	vis[1] = true;
	queue<int> q;
	q.push(1);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(auto child : adj[cur]) {
			if(!vis[child]) {
				q.push(child);
				vis[child] = true;
				par[child] = cur;
			}
		}
	}
}

int main() {
	int n, m;
	cin>>n>>m;

	adj.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);

	for(int i=0; i<=n; i++) {
		par[i] = -1;
	}

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	if(par[n] == -1) {
		cout<<"IMPOSSIBLE";
		return 0;
	}

	int candidate = n;
	stack<int> stk;

	while(candidate != -1) {
		stk.push(candidate);
		candidate = par[candidate];
	}

	cout<<stk.size()<<nl;

	while(!stk.empty()) {
		cout<<stk.top()<<" ";
		stk.pop();
	}

	return 0;
}