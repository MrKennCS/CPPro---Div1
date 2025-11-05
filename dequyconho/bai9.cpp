#include<iostream>
#include<unordered_map>
#include<cstring>
#define ll long long
using namespace std;

ll n;
unordered_map<ll, ll> dp;

ll trau(ll x){
    if(dp[x] != 0) return dp[x];

    ll &res = dp[x];
    res = 0;

    res += trau(x/2);
    res += trau(x/3);

    return res;
}

void solve(){
    cin >> n;
    
    //memset(dp, {}, sizeof(dp));
    dp[0] = 1;
    
    cout << trau(n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}