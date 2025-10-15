#include<iostream>

using namespace std;

int n;
int a[1000009];
int dp[1000009];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i] = max(dp[i-1], dp[i-2]);
        if(i >= 2){
            dp[i] = max(dp[i-1], dp[i-2]) + a[i];
        }
    }
    cout << dp[n];
    /*
    Goi dp[i] la diem lon nhat khi xet den vi tri phong i

    Khi xet den dp[i], ta co 2 trang thai

    TH1: dp[i] la vi tri duoc nem
->  dp[i] = dp[i-1] + a[i];
    dp[i] = dp[i-2] + a[i];
    Vay ta xet max cua dp[i-1] va dp[i-2] roi sau do + a[i]

    TH2: dp[i] la vi tri khong duoc nem
->  dp[i] = dp[i-1];
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}