#include<bits/stdc++.h>

using namespace std;

const int mod = 14062008;

int n, k;
int dp[100005];
bool check[100005];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n >> k;

    memset(check, 0, sizeof(check));

    for(int i=1; i<=k; ++i){
        int tmp;    cin >> tmp;
        check[tmp] = true;
    }

    dp[1] = 1;
    for(int i=1; i<n; ++i){
        if(!check[i]){
            add(dp[i + 1], dp[i]);
            add(dp[i + 2], dp[i]);
        }
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
//    freopen("CURRENT.INP", "r", stdin);
//    freopen("CURRENT.OUT", "w", stdout);
    solve();
}
