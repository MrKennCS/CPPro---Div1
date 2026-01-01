#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
int n, i, sum, lim;
int dp[500 * 500 + 505];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n;

    lim = n * (n + 1) / 2;
    
    if(lim & 1){
        cout << 0;
        return ;
    }
    
    lim /= 2;
    
    // BOTTOM UP
    /*
    dp[1][1] = 1;

    for(int i=1; i<n; ++i){
        for(int sum=1; sum<=lim; ++sum){
            if(dp[i][sum] > 0){
                add(dp[i + 1][sum], dp[i][sum]);
                add(dp[i + 1][sum + i + 1], dp[i][sum]);
            }
        }
    }

    cout << dp[n][lim];
    */

    // TOP DOWN

    dp[1] = 1;

    for(i=2; i<=n; ++i){
        for(sum=lim; sum>=1; --sum){
            if(sum >= i)    add(dp[sum], dp[sum - i]);
        }
    }

    cout << dp[lim];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}