#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
int t, n;
int dp[1000003][2];

void solve(){
    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;

    foru(i, 2, 1000000){
        dp[i][0] = (1LL * dp[i - 1][0] * 4 % mod + dp[i - 1][1] % mod) % mod;
        dp[i][1] = (1LL * dp[i - 1][1] * 2 % mod + dp[i - 1][0] % mod) % mod;
    }

    while(t--){
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    
    solve();
}