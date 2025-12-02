#include<iostream>
#include<cstring>

using namespace std;

/*
Bài toán yêu cầu đếm số cách chia dãy {1, 2, 3, ..., n} thành 2 tập hợp có tống bằng nhau

Nx1: Tổng từ 1 -> n lẻ
=> Ans = 0

Nếu chẵn rồi ta sẽ xét tiếp, thử nghĩ theo hướng QHĐ đếm, ta tư duy như sau:

Ta cần thêm hai chiều để quản lý sum của tập hợp A và B khi xét tới i

-> ta có dp[i][sum_1][sum_2]

Cho chiều [i] quản lý phần tử đang xét

Với mỗi i, ta 2 trường hợp:

    TH1: i vào nhóm A
->  (i, sum_1, sum_2) -> (i + 1, sum_1 + i, sum_2)

    TH2: i vào nhóm B
->  (i, sum_1, sum_2) -> (2 + 1, sum_1, sum_2 + i)

    Nhận xét một chút, nếu dp[i][sum_1][sum_2] thì sẽ RTE, n*(n*(n+1)/2)^2 = ~7x10^12 -> TLE + RTE

    Ta để trạng thái thỏa mãn, ta có thể lượt bỏ chiều sum_2

->  dp[i][sum] là ổn

Với mỗi i, ta có 2 trường hợp:

    TH1: i vào nhóm A
->  (i, sum) -> (i + 1, sum + i)
=>  dp[i + 1][sum + i] += dp[i][sum];

    TH2: i vào nhóm B
->  (i, sum) -> (i + 1, sum)
=>  dp[i + 1][sum] += dp[i][sum]
    */

int tong;
int dp[505][125755];
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void bottomup(int n){
    //cin >> n;
    tong = (n + 1) * n / 2;

    if(tong & 1){
        cout << 0 << '\n';
        return ;
    }

    tong /= 2;
    //memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for(int i=0; i<n; ++i){
        for(int sum=0; sum<=tong; ++sum){
            add(dp[i + 1][sum + i + 1], dp[i][sum]);
            add(dp[i + 1][sum], dp[i][sum]);
            //dp[i + 1][sum + i + 1] += dp[i][sum];
            //dp[i + 1][sum] += dp[i][sum];
        }
    }
    /*
    for(int i=1; i<=n; ++i)     dp[i][0] = i;
    for(int i=1; i<=tong; ++i)  dp[0][i] = i;
    dp[0][0] = 1;
    for(int sum = 0; sum <= tong; ++sum){
        for(int i = 0; i <= n; ++i){
            cout << dp[i][sum] << " ";
        }
        cout << '\n';
    }
    */

    //if(dp[n][tong] & 1) cout << "n = " << n << ": " << dp[n][tong] << " | " << dp[n][tong] / 2 << '\n';
    cout << dp[n][tong] / 2 << '\n';
}

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    freopen("test.INP", "r", stdin);
    freopen("test.OUT", "w", stdout);
    //solve();
    /*
    
    */
    int n;  cin >> n;
    //for(int i=1; i<=100; ++i){
        bottomup(n);
    //}
}