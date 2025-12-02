#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
const int X = 1e6 + 6;
const int N = 105;
int n, x;
int a[N];
int dp[X];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i)    cin >> a[i];

    dp[0] = 1;
    for(int i=0; i<x; ++i){
        for(int j=1; j<=n; ++j){
            add(dp[i+a[j]], dp[i]);
        }
    }

    cout << dp[x];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}