#include<iostream>
#define ll long long
using namespace std;

int n;
int a[1000006];
ll dp[1000006];

void solve(){
    /*
    Trang thai:

    Tai moi thoi diem, ta co cac trang thai:
    - Nguoi choi co the phong hoac khong phong phi tieu

    Tai moi thoi diem, ta co cac dieu kien sau:
    - Voi moi i duoc chon, buoc mot trong 2 thang i-1 hoac i-2 phai la trang thai khong duoc chon
    - Voi moi i khong duoc chon, gia tri tai diem i phu thuoc hoan toan vao 2 gia tri i-1 va i-2(VO NGHIA DO MUON TIM TONG DIEM CAO NHAT) 


    Voi moi trang thai cua i khi xet toi i, ta dinh nghia cua res[i] nhu sau:
    Goi dp[i] la tong diem lon nhat khi xet den lan nem thu i ma van DAM BAO DIEU KIEN KHONG XUNG DOT

    BASE:
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    Voi moi vi tri i, de dam bao DIEU KIEN TREN LA LUON DUNG, ta chi xet cac truong hop dung nhu sau

    i-3 | i-2 | i-1 | i

    Xet den vi tri i, ta co 2 truong hop thoa man sau:

    TH1: Khong chon i
->  dp[i] = dp[i-1]

    TH2: Khong chon i-1
->  dp[i] = dp[i-2] + a[i]

    TH3: Khong chon i-2
->  dp[i] = dp[i-3] + a[i] + a[i-1]

    Vay voi moi vi tri i, ta lay max cua 3 truong hop THOA MAN VOI DIEU KIEN tren de dam bao VOI MOI DP[I], DIEU KIEN LA LUON DUNG
    
    */
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for(int i=3; i<=n; ++i){
        dp[i] += max(dp[i-1], dp[i-2] + a[i]);
        dp[i] = max(dp[i], dp[i-3] + a[i] + a[i-1]);
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}