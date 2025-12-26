#include<iostream>
#include<cstring>

using namespace std;

// SOLUTION
/*
int t, n;
long long dp[1000005][2];
const int mod = 1e9 + 7;

void solve(){
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
*/

// SOLVE EXPLAIN
/*
Goi dp[i] la so cach chia doan tu 1->i thanh cac doan con co it nhat 1 phan tu

BASE: 
dp[1] = 1
dp[2] = 2
dp[3] = 4
dp[4] = 8
*/

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int t, n;
int dp[N][2];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}
/*
3
2
6
1337
*/
void review(){
    cin >> t;

    dp[1][0] = dp[1][1] = 1;
    for(int i=1; i<1000000; ++i){
        if(dp[i][0] > 0){
            add(dp[i + 1][0], 1LL * dp[i][0] * 4 % mod);
            add(dp[i + 1][1], dp[i][0]);
        }
        if(dp[i][1] > 0){
            add(dp[i + 1][1], 1LL * dp[i][1] * 2 % mod);
            add(dp[i + 1][0], dp[i][1]);
        }
    }

    while(t--){
        cin >> n;

        //memset(dp, 0, sizeof(dp));
        
        // TOP DOWN
        /*
        
        dp[1][0] = dp[1][1] = 1;
        for(int i=2; i<=n; ++i){
            add(dp[i][0], (1LL * dp[i - 1][0] * 4 + dp[i - 1][1]) % mod);
            add(dp[i][1], (1LL * dp[i - 1][0] + dp[i - 1][1] * 2) % mod);
        }
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
        */

        // BOTTOM UP


        cout << (1LL * dp[n][0] + dp[n][1]) % mod << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
}