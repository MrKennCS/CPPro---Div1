#include<iostream>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
int a[N];
int dp[N][105];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x %= mod;
}

void solve(){
/*
dp[i][pre] la so cach tao day tu 1->i va pre la gia tri cua phan tu i

B2: CTTH

TH1: a[i] xac dinh (a[i] != 0)
pre[i][a[i]] += pre[i-1][(a[i]-1) -> (a[i]+1)];

TH2: a[i] khong xac dinh
pre[i][1->m] += pre[i-1][(a[i]-1) -> (a[i]+1)]


4 5
2 0 0 3

2 2 2 3
2 2 3 3
2 3 2 3
2 3 4 3
2 1 2 3
2 3 3 3

*/
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];

    if(a[1] == 0)   for(int i=0; i<=m; ++i) dp[1][i] = 1;
    else            dp[1][a[1]] = 1;
    
    for(int i=2; i<=n; ++i){
        if(a[i] != 0){
            /*
            add(dp[i][a[i]], dp[i-1][a[i]-1]);
            add(dp[i][a[i]], dp[i-1][a[i]]);
            add(dp[i][a[i]], dp[i-1][a[i]+1]);
            
            */
            dp[i][a[i]] = (1LL*dp[i][a[i]] + dp[i-1][a[i]-1]) % mod;
            dp[i][a[i]] = (1LL*dp[i][a[i]] + dp[i-1][a[i]]) % mod;
            dp[i][a[i]] = (1LL*dp[i][a[i]] + dp[i-1][a[i]+1]) % mod;
            //cout << i << " " << a[i] << " " << dp[i][a[i]] << " = " << dp[i-1][a[i]-1] << " + " <<  dp[i-1][a[i]] << " + " <<  dp[i-1][a[i]+1] << '\n';
        }else{
            for(int j=0; j<=m; ++j){
                /*
                add(dp[i][j], dp[i-1][j]);3 5

                */

                dp[i][j] = (1LL*dp[i][j] + dp[i-1][j]) % mod;
                if(j >= 0)  dp[i][j] = (1LL*dp[i][j] + dp[i-1][j-1]) % mod;
                if(j <= m)  dp[i][j] = (1LL*dp[i][j] + dp[i-1][j+1]) % mod;
            }
            /*
            cout << "GAY: ";
            for(int j=0; j<=m; ++j) cout << dp[i][j] << " ";
            cout << '\n';
            */
        }
    }
    int res = 0;

    for(int i=0; i<=m; ++i) res = (1LL*res + dp[n][i]) % mod;
    cout << res << '\n';
    /*
5 5
2 0 0 0 2
19
0 0 0 1 3 0 
0 0 1 2 6 0 
0 1 1 3 7 19 
0 0 1 2 6 0
0 0 0 1 3 0
0 0 0 0 1 0
    */
   for(int i=0; i<=m; ++i){
       for(int j=0; j<=n; ++j){
           cout << dp[j][i] << " ";
       }
       cout << '\n';
   }
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
