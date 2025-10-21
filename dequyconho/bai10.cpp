#include<iostream>
#include<cstring>

using namespace std;

int n, mx;
int cnt_50, cnt_1, cnt_2;
int dp[301][301][301][301];
const int mod = 1e9 + 9;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

int trau(int i, int m50, int m1, int m2){
    if(dp[i][m50][m1][m2] != -1)                return dp[i][m50][m1][m2];
    if(cnt_50 > mx || cnt_1 > mx || cnt_2 > mx) return 0;
    if(cnt_50 < 0 || cnt_1 < 0 || cnt_2 < 0)    return 0;
    if(i > n)   return 1;

    int &res = dp[i][m50][m1][m2];

    add(res, trau(i+1, m50+1, m1, m2));

    if(cnt_50 >= 1) add(res, trau(i+1, cnt_50-1, cnt_1+1, cnt_2));

    if(cnt_50 >= 1 && cnt_1 >= 1)   add(res, trau(i+1, cnt_50-1, cnt_1-1, cnt_2+1));
    else if(cnt_50 >= 3)            add(res, trau(i+1, cnt_50-3, cnt_1, cnt_2+1));

    return res;
}

void solve(){
    cin >> n >> mx;
    cin >> cnt_50 >> cnt_1 >> cnt_2;

    memset(dp, -1, sizeof(dp));

    cout << trau(1, cnt_50, cnt_1, cnt_2);
    /*
    Goi dp[1][cnt_50][cnt_1][cnt_2] la so truong hop co the phat kem

    Do thang dp[1][cnt_50][cnt_1][cnt_2] duoc tinh dua vao cac ket qua cua dp[n][...][...][...]
    * Do mot truong hop duoc tinh la hop le hay khong thi khi phat du n ban thi moi biet duoc

    -> Ta se tinh thang dp[1][cnt_50][cnt_1][cnt_2] bang cac bai toan nho hon cua dp[2][...][...][...]

    Khi duyet i=1 voi i -> n, voi moi i ta se co 3 truong hop:
    
    TH1: Thang i dua 50 cent
    -> Thoa man voi moi i -> Truong hop nay luon chay
    -> dp[i][cnt_50][cnt_1][cnt_2] += dp[i+1][cnt_50+1][cnt_1][cnt_2]

    TH2: Thang i dua 1 dollar
    Dieu kien: cnt_50 tai i >= 1

    if(cnt_50 >= 1) dp[i][cnt_50][cnt_1][cnt_2] += dp[i+1][cnt_50-1][cnt_1+1][cnt_2]

    TH3: Thang i dua 2 dollars
    Dieu kien duoc thuc hien theo thu tu uu tien sau:
        1: cnt_50 >= 1 && cnt_1 >= 1    -> dp[i][cnt_50][cnt_1][cnt_2] = dp[i+1][cnt_50-1][cnt_1-1][cnt_2+1]
        2: cnt_50 >= 3                  -> dp[i][cnt_50][cnt_1][cnt_2] = dp[i+1][cnt_50-3][cnt_1][cnt_2+1]


    *BASE: 
    i > n -> return 1
    cnt_50 > mx || cnt_1 > mx || cnt_2 > mx -> return 0;
    cnt_50 < 0 || cnt_1 < 0 || cnt_2 < 0    -> return 0;
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}