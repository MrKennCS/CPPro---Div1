#include<iostream>

using namespace std;

int n;
const int mod = 1e9 + 7;
int dp[1000009];

int cnt;

void backtrack(int target, int sum){
    if(sum >= target){
        if(sum == target)   cnt++;
        return ;
    }

    for(int i=1; i<=6; ++i){
        backtrack(target, sum + i);
    }
}

void solve(){
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    
    for(int i=6; i<=n; ++i){
        dp[i] = dp[i-1] % mod;
        dp[i] = (dp[i] % mod + dp[i-2] % mod) % mod;
        dp[i] = (dp[i] % mod + dp[i-3] % mod) % mod;
        dp[i] = (dp[i] % mod + dp[i-4] % mod) % mod;
        dp[i] = (dp[i] % mod + dp[i-5] % mod) % mod;
        dp[i] = (dp[i] % mod + dp[i-6] % mod) % mod;
        /*
        */
        //dp[i] = dp[i-1] % mod + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
    }
    cout << dp[n];
    //for(int i=1; i<=n; ++i) cout << dp[i] << '\n';
    /*
    Goi dp[i] la so cach tao ra tong i

    Ta co cong thuc truy hoi nhu sau:

    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + d[i-5] + dp[i-6], voi moi i >= 6

    1   1
    2   2
    3   4
    4   8
    5   16
    6   32
    7   63
    8   125

    for(int i=1; i<=8; ++i){
        cnt = 0;
        backtrack(i, 0);
        cout << cnt << '\n';
    }
    */

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}