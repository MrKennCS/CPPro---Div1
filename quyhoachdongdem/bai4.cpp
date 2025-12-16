#include<iostream>

using namespace std;

// KHAI BAO
/*
int n, x;
int c[105];
int dp[1000009];

const int mod = 1e9 + 7;
*/

// GIAI THICH
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

// SOLUTION
/*
void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    //if(x < mod)     x += mod;
}
void solve(){
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
*/

const int mod = 1e9 + 7;
int n, x;
int c[1000005];
int dp[1000005];

/*
    Đề cho n đồng xu, yêu cầu chọn ra các đồng xu sao cho có tổng là x
    LƯU Ý: Ta chỉ đếm những trường hợp các đồng xu được sắp xếp 'gọn gàng'

    *Nhìn vào các cách đề cho, ta có một ý tưởng đếm (dp) như sau:
    
    Với mỗi đồng xu i, ta chọn liên tục nó cho đến x, như vậy ta sẽ đảm bảo được các đồng xu có giá trị như nhau sẽ luôn đứng gần nhau:

    Ta sẽ dùng dp như sau

    Ta cần quản lý:
        + Số các đồng xu
        + Tổng các đồng xu

->  dp[i][sum]

    BASE:
    dp[0][0] = 1

    Vỡi môi i, ta sẽ cộng liên tục tổng như sau:

    dp[i + k*i] += dp[i]
*/

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void review(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=x; ++j){
            if(j - c[i] >= 0)   add(dp[j], dp[j - c[i]]);
            //dp[i][j] += dp[i][j - c[i]];
        }
    }

    /*
    for(int i=1; i<=n; ++i) dp[i][0] = i;
    for(int i=1; i<=x; ++i) dp[0][i] = i;

    for(int i=0; i<=n; ++i){
        for(int j=0; j<=x; ++j){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    cout << dp[x];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review();
}