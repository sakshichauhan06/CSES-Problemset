#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

int main() {
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++){
        ll total_comb = ((i*i)*((i*i)-1))/2;
        ll attack_knight = 4*(i-1)*(i-2);
        ll ans = total_comb - attack_knight;
        cout<<ans<<nl;
    }

    return 0;
}