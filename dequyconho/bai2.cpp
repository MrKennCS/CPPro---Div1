#include<iostream>

using namespace std;

int n;
int t[60006];
int r[60006];
int dp[60006];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i)     cin >> t[i];
    for(int i=1; i<=n-1; ++i)   cin >> r[i];

    /*
    goi dp[i] la thoi gian mua be nhat khi xet  den nguoi thu i

    Khi xet dep dp[i], ta co 2 trang thai:

    TH1: nguoi thu i mua mot minh

    dp[i] = dp[i-1] + t[i]

    TH2: nguoi thu i da duoc nguoi thu i-1 mua cho

    dp[i] = dp[i-2] + r[i-1]

    * Chu y o day khi xet truong hop 2, i phai >= 2 moi duoc xet 

    -> Moi lan xet dp[i], ta chi can lay min cua 2 truong hop tren
    */
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i] = dp[i-1] + t[i];
        if(i >= 2)  dp[i] = min(dp[i], dp[i-2] + r[i-1]);
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}