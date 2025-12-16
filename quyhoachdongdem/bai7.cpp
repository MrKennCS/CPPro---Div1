#include<iostream>
#include<cstring>

using namespace std;

// GIAI THICH
    /*
    Cac trang thai ta dang co la:

    n: chieu dai cua day den
    t: so thao ta can duoc thuc hien
    a: so bong den xanh can co sau khi thuc hien t buoc
    b: so bong den do can co sau khi thuc hien t buoc

    Yeu cau de: tinh so cach tao duoc mot day den n den voi a bong xanh va b bong do sau t buoc

    Ta can luu y cac trang thai:
    t: thao tac thu
    a: so bong den xanh o moi trang thai
    b: so bong den do o moi trang thai

    Goi dp[t][a][b] la so cac tao day n den co a den xanh va b den do o t buoc

    dp[0][0][0] = 1;

    Ta duyet t tang dan tu 0 -> n-1

    voi moi dp[t][a][b] ta co the cap nhat cho cac trang thai:

    TH1: dp[t+1][a+1][b]    , trang thai chuyen 1 bong tat BAT KY sang xanh 
    TH2: dp[t+1][a-1][b+1]  , trang thai chuyen 1 bong xanh BAT KY sang do
    TH3: dp[t+1][a][b-1]    , trang thai chuyen 1 bong do BAT KY sang tat

    Vi ta dang dem SO CACH, voi moi trang thai ta phai nhan vao so den o trang thai do

->  Ta co cach cap nhat o moi trang thai nhu sau:

    dp[t+1][a+1][b]     += dp[t][a][b]*(n-a-b)  , khong dieu kien
    dp[t+1][a-1][b+1]   += dp[t][a][b]*a        , a >= 1
    dp[t+1][a][b-1]     += dp[t][a][b]*b        , b >= 1
    */

// SOLUTION
/*
const int mod = 1e9 + 7;    
const int N = 606;
int n, t, a, b;
int dp[2][N][N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    //if(x < mod)     x += mod;
}

void solve(){

    cin >> n >> t >> a >> b;
    dp[0][0][0] = 1;
    for(int i=0; i<t; ++i){
        int nx = (i+1)&1;
        memset(dp[nx], 0, sizeof(dp[nx]));
        for(int _a=0; _a<=min(n, i); ++_a){
            for(int _b=0; _b<=min(n-_a, i); ++_b){
                if(dp[i&1][_a][_b] > 0){
                    add(dp[nx][_a+1][_b], (1LL*dp[i&1][_a][_b]*(n-_a-_b)) % mod);
                    if(_a >= 1) add(dp[nx][_a-1][_b+1], (1LL*dp[i&1][_a][_b]*(_a)) % mod);
                    if(_b >= 1) add(dp[nx][_a][_b-1], (1LL*dp[i&1][_a][_b]*(_b)) % mod);
                }
            }
        }
    }

    cout << dp[t&1][a][b];
}
*/

void review(){
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review();
}