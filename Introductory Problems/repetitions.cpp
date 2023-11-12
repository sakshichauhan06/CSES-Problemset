#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
    
    int maxi=0, count=1;
    string s;
    cin>>s;

    int n = s.length();

    if(n == 1) {
        cout<<1;
        return 0;
    }

    for(int i=0; i<n-1; i++) {
        if(s[i] == s[i+1]) {
            count++;
        } else {
            count = 1;
        }
        maxi = max(maxi, count);
    }
    cout<<maxi;
    
    return 0;
}