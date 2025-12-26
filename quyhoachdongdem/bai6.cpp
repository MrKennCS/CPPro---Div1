#include<iostream>

using namespace std;

/*
int n, k;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int h[N];
int dp[2*N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}
*/

//void solve(){
    /*
    Ta co cac trang thai:
    
    N la chieu cao can dat khi chong cac chong go len
    h[i] la chieu cao cua chong go thu i

    k la so chong go

    Yeu cau de bai keu dem so cach xep cac khuc go tuy y
    voi moi khuc  go duoc xem bao nhieu lan cung duoc de tao thanh
    mot chong go cao N don vi

    Ta can luu y 2 trang thai: N vaf h[i]

->  Goi dp[i] la so cach xep cac cot go thanh mot chong go co chieu cao i

    BASE: dp[0] = 1

    Voi moi trang thai dp[i] ta co the cap nhat den trang thai dp[i + h[j]]

    Nhu vay, voi moi trang thai dp[i], ta cap nhat trang thai nhu sau:

    dp[i + h[j]] += dp[i]
    */

    /*
    ### SOLVE
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> h[i];

    dp[0] = 1;
    for(int i=0; i<=n; ++i){
        for(int j=1; j<=k; ++j){
            add(dp[i+h[j]], dp[i]);
        }
    }

    cout << dp[n];
}
    */

/*
    Cho k loại khối gỗ, không hạn chế số lượng và chiều cao là h1, h2, h3, ... hk

    Tìm số cách xếp từ các khối gỗ đẻ đạt độ cao N

    Ta sẽ có những dữ kiện cần quản lý cho mỗi trạng thái (mỗi cách)
        + Độ cao hiện tại

->  dp[sum]

    Với mỗi dp[sum: 1 -> n]

    dp[sum] += dp[sum - a[i]] voi a[i] la khoi go thu i


*/

const int mod = 1e9 + 7;
const int N = 100005;
const int K = 1005;
int n, k;
int h[K];
int dp[N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void review(){
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> h[i];

    dp[0] = 1;
    for(int sum=1; sum<=n; ++sum){
        for(int i=1; i<=k; ++i){
            if(sum - h[i] >= 0) add(dp[sum], dp[sum - h[i]]);
        }
    }    

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
}