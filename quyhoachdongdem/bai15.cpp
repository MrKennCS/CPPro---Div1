#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int n;
double a[3003];
double dp[3003][3003];

void solve(){
    cin >> n;
    foru(i, 1, n)   cin >> a[i];

    dp[0][0] = 1;
    foru(i, 1, n)   dp[i][0] = dp[i - 1][0] * (1 - a[i]);

    

    

    /*
    foru(i, 1, n){
        foru(j, 1, n){
            dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];
        }
    }

    foru(i, 1, n){
        foru(j, 1, n){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    double res = 0;
    foru(i, n/2+1, n)   res += dp[n][i];

    cout << setprecision(9) << fixed << res;
}

double trau(int i, int cnt){
    if(dp[i][cnt] != 0) return dp[i][cnt];
    if(cnt > i)    return 0;

    double &res = dp[i][cnt];
    res = 0;

    res += trau(i - 1, cnt) * (1 - a[i]);
    res += trau(i - 1, cnt - 1) * a[i];

    return res;
}

void solve1(){
    cin >> n;
    foru(i, 1, n)   cin >> a[i];

    dp[0][0] = 1;
    foru(i, 1, n)   dp[i][0] = dp[i - 1][0] * (1 - a[i]);

    double res = 0;
    foru(i, n/2+1, n)   res += trau(n, i);
    
    /*
    foru(i, 0, n){
        foru(j, 0, n){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    cout << setprecision(9) << fixed << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    solve1();
}