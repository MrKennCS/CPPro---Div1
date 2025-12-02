#include<iostream>

using namespace std;

const int N = 103;
const int M = 10003;
const int lim = 1e5 + 3;
int n, m;
int sz;
int pos;
int w[lim];
int v[lim];
int a[N];
int dp[lim][M];

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; ++i){
        cin >> w[i] >> v[i] >> a[i];
        sz += a[i];
    }

    pos = sz;
    for(int i=n; i>=1; --i){
        for(int j=1; j<=a[i]; ++j){
            w[pos] = w[i];
            v[pos] = v[i];
            pos--; 
        }
    }

    for(int i=1; i<=sz; ++i){
        for(int j=1; j<=m; ++j){
            if(j - w[i] >= 0)   dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][m];
}
/*
3 4
1 4 2
2 7 2
3 6 1
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}