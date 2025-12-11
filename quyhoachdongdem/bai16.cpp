#include<bits/stdc++.h>
#define float double
using namespace std;

int n;
double a[3003];
double dp[3003];
double res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i]; 

    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        for(int cnt=i; cnt>=1; --cnt){
            //cout << a[i] * dp[cnt-1] << " " << (1 - a[i]) * dp[cnt] << '\n';
            dp[cnt] = a[i]*dp[cnt-1] + (1-a[i])*dp[cnt];
        }
        /*
        cout << "TRUONG HOP i = " << i << '\n';
        for(int j=0; j<=n; ++j) cout << dp[j] << '\n';
        */
        dp[0] *= (1 - a[i]);
    }

    for(int i=n/2+1; i<=n; ++i) res += dp[i];

    cout << setprecision(10) << fixed << res;
}

/*
3
0.3 0.6 0.8
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}