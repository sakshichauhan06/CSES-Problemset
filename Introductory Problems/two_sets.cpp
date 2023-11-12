#include<bits/stdc++.h>
// #define int int64_t
#define nl "\n"
using namespace std;

int main() {
	int n;
	cin>>n;

	if(n%2 != 0 && n != 3) {
		cout<<"NO";
	} else if(n == 3) {
		cout<<"YES"<<nl;
		
		cout<<2<<nl;
		cout<<1<<" "<<2<<nl;
		cout<<1<<nl;
		cout<<3;
	}


	return 0;
}

2 no
1 2

4 yes
1 2 3 4
1 4
2 3

left < right
even nums mein
or nums ka array is divided into 
even num, then yes
otherwise no.

6 no
1 2 3 4 5 6
1 6 3 
2 5 4

// 8 yes
// 1 2 3 4 5 6 7 8
// 1 8 6 3
// 2 7 5 4

10
1 2 3 4 5 6 7 8 9 10 
1 10
2 9 

// 3 7 11 15 19 23
// 5 9 13 17 21 25

// 3 yes
// 1 2 3
// 1 2
// 3

// 5 no
// 1 2 3 4 5
// 1 5 3
// 4 2

// 7 no
// 1 2 3 4 5 6 7
// 1 7 5 3
// 6 2 4

// 9 no
// 1 2 3 4 5 6 7 8 9
// 1 9 3 7 5
// 2 8 4 6

// 11 no
// 1 2 3 4 5 6 7 8 9 10 11
// 1 11 3 9 5 7
// 2 10 4 8 6

// 13 no
// 1 2 3 4 5 6 7 8 9 10 11 12 13
// 1 13 3 11 5 9 6 8
// 2 12 4 10 6 8 7

// 15 no
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 1 15 3 13 5 11 7 9
// 2 14 4 12 6 10 8
