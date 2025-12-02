#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, k;
int a[N];
int dp[N];
int sum[N];
int pos;
/*
Goi dp[i] la so cach chia doan con thoa man YCDB khi xet den vi tri i

BASE:
dp[0] = 1
dp[1] = 1

Ta xet bai toan con: i-1, co 2 truong hop

TH1: i se tu tach ra thanh mot nhom rieng
-> dp[i] = dp[i-1]

TH2: i se gop chung nhom voi i-1

LUU Y: De i co the gop chung nhom voi i-1, ta can thoa man:
+ a[i] == a[i-1]
+ Do dai tu vi tri L den vi tri i <= k, hay i - L + 1 <= k
    GIAI THICH: L o day la vi tri xa i nhat ma van thoa DIEU KIEN TREN
    VAY TA XAC DINH L NHU THE NAO?

    De y thay cac vi tri tu L -> i phai giong nhau, ta co the:
    + pos la vi tri xa i nhat sao cho moi phan tu tu pos -> i deu giong nhau

    Khi nay, voi moi L, L >= pos
    ma i - L + 1 <= k   -> L >= i - k + 1

    De dong thoi thoa man 2 dieu kien, ta co the gop chung lai:

    L >= max(pos, i - k + 1)

    Nhu vay, khi nay ta se xet ta cac cac bai toan di-p[max(pos, i-k+1) -> 1]

    Ta nhan thay, bai toan dp[i] khi nay se duoc cap nhat boi bai toan dp[max(pos, i-k+1) -> 1]
    Nhan thay dp[max(pos, i-k+1) -> 1] la mot mang cong don -> Toi uu hoa

    Nhu vay quay lai ve TH2, voi moi truong hop 2, ta:

- a[i] == a[i-1] ?
    no -> dp[i] = dp[i-1] (giong TH1)
    yes -> dp[i] = dp[max(pos, i-k+1) -> i-1] = sum[i-1] - sum[max(pos, i-k+1) - 1]
*/
int get(int l, int r){
    if(l == 0)  return sum[r] % mod;
    return (sum[r] - sum[l-1] + mod) % mod;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cin >> k;

    dp[0] = dp[1] = 1;
    sum[0] = 1;
    sum[1] = 2;
    pos = 1;

    for(int i=2; i<=n; ++i){
        if(a[i] != a[i-1]){
            dp[i] = dp[i-1];
            pos = i;
        }else{
            int l = max(pos, i-k+1);
            dp[i] = get(l-1, i-1);
        }
        sum[i] = (sum[i-1] + dp[i]) % mod;
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}