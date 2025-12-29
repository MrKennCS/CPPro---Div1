#include<bits/stdc++.h>
#define float double
using namespace std;

// SOLUTION
/*
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
        dp[0] *= (1 - a[i]);
    }

    for(int i=n/2+1; i<=n; ++i) res += dp[i];

    cout << setprecision(10) << fixed << res;
}
*/

int n;
double a[3005];
double dp1[3005];

void review2(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp1[0] = 1;

    for(int i=1; i<=n; ++i){
        for(int cnt=n; cnt>=1; --cnt){
            dp1[cnt] = dp1[cnt] * (1 - a[i]) + dp1[cnt - 1] * a[i];
        }
        dp1[0] *= (1 - a[i]);
    }

    double res1 = 0;
    for(int i=n/2+1; i<=n; ++i) res1 += dp1[i];

    cout << setprecision(9) << fixed  << res1;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review2();
}