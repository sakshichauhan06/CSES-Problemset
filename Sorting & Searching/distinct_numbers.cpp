#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long int
#define int int64_t

int32_t main() {

	int n;
	cin>>n;
	set<int> s;

	for(int i = 0; i < n; i++) {
		int k;
		cin>>k;
		s.insert(k);
	}

	cout<<s.size();



	return 0;
}