#include<iostream>

using namespace std;

int n, x;
int c[105];
int dp[1000009];

const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    //if(x < mod)     x += mod;
}

void solve(){
    /*
    Ta co, trang thai cua DP voi moi i la:

    x: tong cua cac phan tu bang x

    Ta goi dp[x] la so cach tao thanh day CO CAC PHAN TU GIONG NHAU
    O GAN NHAU voi tong bang x

    Neu nhu de chon ra cac phan tu giong nhau co vi tri sat nhau,
    ta chi viec duyet moi phan tu roi sau do duyet x

    BASE: dp[0] = 1;

    Voi moi i, ta co cac truong hop:

    if(x-c[j] >= 0) dp[x] += dp[x-c[j]]

    */
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=x; ++j){
            if(j-c[i] >= 0)  add(dp[j], dp[j-c[i]]);
        }
    }
    //add(dp[x], 0);
    cout << dp[x] % mod;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}