#include<iostream>
#include<cstring>

using namespace std;

int n;
int dp[1000009];
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int trau(int sum){
    if(dp[sum] != -1)   return dp[sum];
    if(sum == 0 || sum == 1 || sum == 2 || sum == 3 || sum == 4 || sum == 5)    return dp[sum];

    int &res = dp[sum];
    res = 0;

    add(res, trau(sum - 1));
    add(res, trau(sum - 2));
    add(res, trau(sum - 3));
    add(res, trau(sum - 4));
    add(res, trau(sum - 5));
    add(res, trau(sum - 6));

    return res;
}

void solve(){
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;

    for(int i=6; i<=n; ++i){
        //dp[i] = dp[i-1] % mod;
        add(dp[i], dp[i-1]);
        add(dp[i], dp[i-2]);
        add(dp[i], dp[i-3]);
        add(dp[i], dp[i-4]);
        add(dp[i], dp[i-5]);
        add(dp[i], dp[i-6]);

        //cout << i << " " << dp[i] << '\n';
    }

    cout << dp[n];
    /*
    De bai yeu cau: Tim so cach gieo xuc xac lien tuc co tong bang n

->  Nhan xet: Bai toan gieo xuc xac lien tuc co tong bang n phu thuoc vao 6 bai toan con la
    i - 1; i - 2; i - 3; i - 4; i - 5; i - 6

    Goi dp[i] la so cach de gieo xuc xac lien tuc co tong bang i

    BASE:
    dp[0] = 0;
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    dp[4] = 8
    dp[5] = 16

    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6], voi moi i >= 6
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();

    /*
    cin >> n;

    memset(dp, -1, sizeof(dp));

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;

    cout << trau(n);
    */
}