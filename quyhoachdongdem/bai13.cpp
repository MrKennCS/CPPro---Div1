#include<iostream>

using namespace std;

int t, n;
long long dp[1000005][2];
const int mod = 1e9 + 7;

void solve(){
/*

Goi dp[i] la so cach chia doan tu 1->i thanh cac doan con co it nhat 1 phan tu

BASE: 
dp[1] = 1
dp[2] = 2
dp[3] = 4
dp[4] = 8
*/
    cin >> t;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=1000000; ++i){
        dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4) % mod;
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