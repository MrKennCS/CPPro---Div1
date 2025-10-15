#include<iostream>
#include<cstring>

using namespace std;

int k, n;
const int mod = 14062008;
int dp[100009];

void solve(){
    cin >> n >> k;
    
    /*
    Goi dp[i] la so cach de Lucky leo den bac thang thu i

    TH1: dp[i] bi hu
->  dp[i] = 0

    TH2: dp[i] khong bi hu
->  dp[i] = dp[i-1] + dp[i-2];

    * Luu y:
    dp[i-1] xac dinh khi khong hu && i >= 1
    dp[i-2] xac dinh khi khong hu && i >= 2

    */
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=k; ++i){
        int hu; cin >> hu;
        dp[hu] = 0;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; ++i){
        if(dp[i] == 0)  continue;
        dp[i] = dp[i-1] % mod + dp[i-2] % mod;
        dp[i] %= mod;
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}