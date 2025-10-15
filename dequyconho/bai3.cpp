#include<iostream>

using namespace std;

int a[100009];
int dp[100009];

void solve(){
    int q;  cin >> q;


    /*
    Goi dp[i] la so lon nhat trong doan tu 1 -> i

    Ta co cong thuc truy hoi nhu dau:

    dp[i] = max(dp[i-1], a[i]);

    */
    a[0] = 0;
    a[1] = 1;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=1; i<=50000; ++i){
        a[2 * i] = a[i];
        a[2 * i + 1] = a[i] + a[i + 1];
        dp[2 * i] = max(dp[2 * i - 1], a[2 * i]);
        dp[2 * i + 1] = max(dp[2 * i], a[2 * i + 1]);
    }

    while(q--){
        int n;  cin >> n;
        cout << dp[n] << '\n';
    }

    //cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}