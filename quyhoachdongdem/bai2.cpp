#include<iostream>

using namespace std;

int n, k;
int dp[100006];
const int mod = 14062008;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> k;

    dp[1] = 1;

    for(int i=1; i<=k; ++i){
        int x;  cin >> x;
        dp[x] = -1;
    }

    for(int i=2; i<=n; ++i){
        if(dp[i] == -1) continue;
        if(dp[i-1] != -1)    add(dp[i], dp[i-1]);
        if(dp[i-2] != -1)    add(dp[i], dp[i-2]);
    }
    /*
    for(int i=1; i<=n; ++i){
        cout << dp[i] << " ";
    }
    */
    cout << dp[n];
    /*
    Goi dp
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}