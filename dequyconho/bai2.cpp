#include<iostream>

using namespace std;

int n;
int t[60006];
int r[60006];
int dp[60006];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> t[i];
    for(int i=1; i<=n-1; ++i)   cin >> r[i];

    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i] = dp[i-1] + t[i];
        if(i>=2){
            dp[i] = min(dp[i], dp[i-2] + r[i-1]);
        }
    }

    cout << dp[n];
    /*
    5
    2 5 7 8 4
    4 9 10 10

    Bai toan can gi?
    -> Thoi gian mua ve ngan nhat cua n nguoi

    Goi dp[i] la thoi gian mua ve ngan nhat xet den nguoi thu i

    De biet dp[i], ta can xet bai toan dp[i-1], voi 2 truong hop nhu sau:

    TH1: Nguoi thu i mua ve cho chinh minh
->  dp[i] = dp[i-1] + t[i];
    Sau do xet tiep bai toan i+1

    TH2: Nguoi thu i mua ve cho chinh minh va nguoi thu i + 1
->  dp[i] = dp[i-1] + r[i];
    Sau do xet tiep nguoi thu i+2
    * Luu y, de xet truong hop 2 ta can thoa i+1 <= n

    Voi moi vi tri i, ta xet truong hop 1 neu t[i] < r[i] va nguoc lai

    Truong hop BASE:
    dp[0] = 0
    
    */
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    solve();
}