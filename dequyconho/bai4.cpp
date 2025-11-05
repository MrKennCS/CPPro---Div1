#include<iostream>

using namespace std;

int n, k;
int dp[100009];
const int mod = 14062008;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> k;

    dp[0] = 0;
    dp[1] = 1;
    for(int i=1; i<=k; ++i){
        int t;  cin >> t;
        dp[t] = -1;
    }
    for(int i=2; i<=n; ++i){
        if(dp[i] == -1) continue;
        if(dp[i-1] != -1)   add(dp[i], dp[i-1]);
        if(dp[i-2] != -1)   add(dp[i], dp[i-2]);
    }

    cout << dp[n];
    /*
    Nhan xet:
    Bai toan can tim so cach di tu bac thang 1 -> n

->  Ta di tim bai toan so cach di tu bac thang 1 -> i
->  Bai toan i phu thuoc vao bai toan i-1
=>  Duyet tu 1 -> n

    TRANG THAI & DINH NGHIA
    Goi dp[i] la so cách đi từ bậc thang thứ 1 -> i

    BASE: 
    dp[0] = 0;
    dp[1] = 1;

    Voi moi i, ta can de i 2 trang thai:

    dp[i-1] và dp[i-2]

->  dp[i] = dp[i-1] + dp[i-2]

    NHƯNG SẼ CÓ NHỮNG BẬC THANG BỊ HƯ
->  dp[i] = -1; để đánh dấu.
->  Nếu một trong hai dp[i-1] và dp[i-2] bị hư thì ta không cập nhật vào dp[i]


    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}