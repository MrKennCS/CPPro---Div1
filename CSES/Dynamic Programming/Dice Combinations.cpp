#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long

using namespace std;

int n;
int dp[1000007];
const int mod = 1e9 + 7;
/*

*/

int trau(int sum){
    if(dp[sum] != -1)   return dp[sum];

    int &res = dp[sum];
    res = 0;

    /*
    
    */

    res = trau(sum - 1) % mod;
    res = (res % mod + trau(sum - 2) % mod) % mod;
    res = (res % mod + trau(sum - 3) % mod) % mod;
    res = (res % mod + trau(sum - 4) % mod) % mod;
    res = (res % mod + trau(sum - 5) % mod) % mod;
    res = (res % mod + trau(sum - 6) % mod) % mod;

    return res;
}

void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;

    cout << trau(n);
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}