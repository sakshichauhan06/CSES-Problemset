#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

int n, m;
vector<vector<bool>> vis;

void dfs(int i, int j) {
	if(i<0 || i>=n || j<0 || j>=m) return;
	if(vis[i][j]) return;

	vis[i][j] = true;;

	dfs(i+1, j);
	dfs(i, j+1);
	dfs(i-1, j);
	dfs(i, j-1);
}

int main() {
	
	cin>>n>>m;
	vis.resize(n);

	for(int i=0; i<n; i++) {
		vis[i].resize(m);
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin>>c;
			if(c == '#') {
				vis[i][j] = true;
			}
		}
	}

	int count = 0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!vis[i][j]) {
				dfs(i, j);
				count++;
			}
		}
	}

	cout<<count;



	return 0;
}