#include<iostream>
//#define int long long
using namespace std;

// SOLUTION
/*
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
int a[N];
int dp[N][105];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];

    if(a[1] == 0)   for(int i=1; i<=m; ++i) dp[1][i] = 1;
    else            dp[1][a[1]] = 1;
    
    for(int i=2; i<=n; ++i){
        if(a[i] != 0){
            for(int j=max(1, a[i]-1); j<=min(a[i]+1, m); ++j){
                add(dp[i][a[i]], dp[i-1][j]);
            }
        }else{
            for(int j=1; j<=m; ++j){
                for(int k=max(1, j-1); k<=min(m, j+1); ++k){
                    add(dp[i][j], dp[i-1][k]);
                }
            }
        }
    }

    int res = 0;
    for(int i=0; i<=m; ++i) add(res, dp[n][i]);
    cout << res << '\n';
}
*/


const int N = 1e5 + 5;
const int M = 1e2 + 5;
const int mod = 1e9 + 7;
int n, m;
int a[N];
int dp[N][M];

void add(int &x, int y){
    x += y;
    if(x >= mod)  x -= mod;
}

void review(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    
    // BASE
    if(a[1] == 0)   for(int i=1; i<=m; ++i) dp[1][i] = 1;
    else            dp[1][a[1]] = 1;

    for(int i=2; i<=n; ++i){
        if(a[i] != 0){
            add(dp[i][a[i]], dp[i - 1][a[i]]);
            if(a[i] > 1)    add(dp[i][a[i]], dp[i - 1][a[i] - 1]);
            if(a[i] < m)    add(dp[i][a[i]], dp[i - 1][a[i] + 1]);
        }else{
            for(int j=1; j<=m; ++j){
                add(dp[i][j], dp[i - 1][j]);
                if(j > 1)    add(dp[i][j], dp[i - 1][j - 1]);
                if(j < m)    add(dp[i][j], dp[i - 1][j + 1]);
            }
        }
    }

    int res = 0;
    for(int i=1; i<=m; ++i) add(res, dp[n][i]);

    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
    //solve();
}