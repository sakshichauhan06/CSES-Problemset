#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

int n, m;
int sx, sy, dx, dy;

vector<vector<bool>> vis;
vector<vector<pair<int, int>>> path;

vector<pair<int, int>> moves = {
	{1, 0}, 
	{0, 1}, 
	{-1, 0}, 
	{0, -1}
};

bool isValid(int x, int y) {
	if(x < 0 || x >=n || y < 0 || y >= m) return false;
	if(vis[x][y]) return false;

	return true;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({sx, sy});

	while(!q.empty()) {
		pair<int, int> v = q.front();
		int x = v.first;
		int y = v.second;
		q.pop();

		for(auto move : moves) {
			int childx = x + move.first;
			int childy = y + move.second;

			if(!isValid(childx, childy)) continue;

			if(!vis[childx][childy]) {
				q.push({childx, childy});
				vis[childx][childy] = true;
				path[childx][childy] = {childx-x, childy-y};
			}
		}
	}
}

int main() {

	cin>>n>>m;
	vis.resize(n);
	path.resize(n);

	for(int i=0; i<n; i++) {
		vis[i].resize(m);
		path[i].resize(m);
	}

	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin>>c;
			if(c == '#') {
				vis[i][j] = true;
			}
			if(c == 'A') {
				sx = i;
				sy = j;
			}
			if(c == 'B') {
				dx = i;
				dy = j;
			}
		}
	}

	bfs();

	if(!vis[dx][dy]) {
		cout<<"NO"<<nl;
		return 0;
	}

	cout<<"YES"<<nl;

	vector<pair<int, int>> ans;
	pair<int, int> dest = {dx, dy};

	while(dest.first != sx || dest.second != sy) {
		ans.push_back(path[dest.first][dest.second]);
		dest.first -= ans.back().first;
		dest.second -= ans.back().second;
	}

	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<nl;

	for(auto k : ans) {
		if(k.first == 1 && k.second == 0) {
			cout<<'D';
		} else if(k.first == 0 && k.second == 1) {
			cout<<'R';
		} else if(k.first == -1 && k.second == 0) {
			cout<<'U';
		} else if(k.first == 0 && k.second == -1) {
			cout<<'L';
		}
	}

	return 0;
}