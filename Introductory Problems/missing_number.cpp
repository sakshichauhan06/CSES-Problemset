#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
    
    int n;
    cin>>n;

    int s1=0, s2=0;

    s2 = n*(n+1)/2;

    for(int i=0; i<n-1; i++) {
        int x;
        cin>>x;
        s1+=x;
    }

    int ans = s2 - s1;
    cout<<ans;

    return 0;
}