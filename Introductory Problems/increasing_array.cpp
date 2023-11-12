#include<bits/stdc++.h>
#define int int64_t
#define nl "\n"
using namespace std;

int32_t main() {
    
    int n;
    cin>>n;

    int arr[n];
    int ans=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout<<ans;

    return 0;
}