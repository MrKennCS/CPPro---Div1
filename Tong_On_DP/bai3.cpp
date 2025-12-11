#include<iostream>

using namespace std;

/*
int n;
int a[1000005];
long long dp[1000005][2];
*/

void solve(){
    /*
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[1][0] = 0;
    dp[1][1] = a[1];

    for(int i=2; i<=n; ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][1], 1LL * dp[i-1][0] + a[i]);
    }

    cout << max(dp[n][0], dp[n][1]);
    */

/*
Voi moi i, ta co 3 truong hop

    BASE:
    dp[1][0] = 0;
    dp[1][1] = a[1];

    TH1: khong chon a[i]

    dp[i][0] = dp[i-1][0]
    dp[i][1] = dp[i-1][1]

    TH2: cong a[i] vao

    dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + a[i];
    dp[i][0] = dp[i-1][0]

    TH3: tru them a[i]

    dp[i][1] = dp[i-1][1]
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]) - a[i];



    RES = max(dp[n][0], dp[n][1]);
*/
}

int n;
int a[1000006];
long long dp[1000006][2];

void review(){
    /*
    Tìm số điểm lớn nhất có thể đạt được -> DP

    Đầu tiên ta sẽ xét qua từng phần từ của mãng

    ### CASE:
    7
    4 9 2 4 1 3 7

    dp[i][2]

    dp[i][0]: [số được chọn cuối] > 0
    dp[i][1]: [số được chọn cuối] < 0

    Với mỗi i, ta có 3 trạng thái cần chú ý:

    TH1: i không được chọn
    dp[i] = dp[i-1]

    TH2: i được chọn là số dương
    dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][0]);

    TH3: i được chọn là số âm
    dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1]);

    */
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[1][0] = a[1];
    dp[1][1] = 0;

    for(int i=2; i<=n; ++i){
        dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1]);
    }

    cout << max(dp[n][1], dp[n][0]);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
}