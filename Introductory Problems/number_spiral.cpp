#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        ll ans;
        if(x<y){
            if(y%2!=0){
                ans = (y*y)-x+1;
            }
            else{
                ans = ((y-1)*(y-1))+x;
            }
            cout<<ans<<nl;
        }
        else{
            if(x%2!=0){
                ans = ((x-1)*(x-1))+y;
            }
            else{
                ans = (x*x)-y+1;
            }
            cout<<ans<<nl;
        }
    }

    return 0;
}