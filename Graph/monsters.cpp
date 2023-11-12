#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

int n, m;
int count;
vector<vector<bool>> vis;

vector<pair<int, int>> move = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
}

bool isValid(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	if(vis[x][y]) return false;
	return true;
}

void dfs(int i, int j) {
	if(!isValid(i, j)) return;
	vis[i][j] = true;
	count++;

	dfs(count, i+1, j);
	dfs(count, i, j+1);
	dfs(count, i-1, j);
	dfs(count, i, j-1);
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
			if(c == '#') vis[i][j] = true;
			if(c == 'A') dfs(count, i, j, vis);
		}
	}

	return 0;
}