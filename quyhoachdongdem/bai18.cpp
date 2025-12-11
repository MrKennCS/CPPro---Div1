#include<iostream>

using namespace std;

/*
Yeu cau de bai la dem so luong day thoa man

-> Vay cach de tao mang o day la gi?

Ta thử nghĩ theo hướng DP

Với [i] la phần tử thứ i ta dang xét

Với mỗi i, ta có các trường hợp:

3 2 2
6

BASE:

dp[k] = m
x   

TH1: đã tồn tại k dãy liên tiếp bằng nhau trước đó rồi

dp[i] += dp[i-1]*m

TH2: chưa tồn tại k dãy liên tiếp bằng nhau trước đó
-> Khi này ta hình dung với mỗi trường hợp trước đó ta đã xuất hiện k phần tử liên tiếp giống nhau
chính là k phần tử đầu tiên của dãy phải luôn giống nhau?

ĐÚNG, Ở TRƯỜNG HỢP 1, TA CHỈ XÉT LUÔN ĐÚNG KHI VÀ CHỈ KHI K PHẦN TỬ ĐẦU TIÊN 
CHÍNH LÀ K PHẦN TỬ LIÊN TIẾP GIỐNG NHAU

Vậy trong trường hợp thứ 2 này, ta xét các trường hợp khác mà tại đó
có thể k phần tử liên tiếp đầu tiên không giống nhau

khi này ta phải lưu ý một điều rằng k phần tử cuối cùng sẽ là k phần tử liên tiếp giống nhau

dp[i-k] sẽ cập nhật cho dp[i]

dp[i] += dp[i-k]*m

NHƯNG, TA CẢM NHẬN VÀ NHẬN XÉT THẤY CÔNG THỨC TRÊN TÍNH CẢ NHỮNG TRƯỜNG HỢP BỊ TRÙNG NHƯ SAU:

1 1 2 | 2

1 1 | 2 2

Khi này

ta chỉ tính những trường hợp không bị trùng trước đó, hay những trường hợp KHÔNG BỊ TRÙNG ở dp[i-k]

dp[i] += (m^i - dp[i-k]) * (m - 1)
*/


const int mod = 1e9 + 7;
const int N = 1e6 + 6;
int n, m, k;
int dp[N];

void add(int &x, int y){
    x += y;
    while(x >= mod) x -= mod;
}

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)   ans = 1LL * a * ans % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve(){
    cin >> n >> m >> k;

    dp[k] = m;
    for(int i=k+1; i<=n; ++i){
        add(dp[i], 1LL * dp[i-1] * m % mod);
        add(dp[i], (1LL * binpow(m, i-k) - dp[i-k] + mod) * (m - 1) % mod);
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}