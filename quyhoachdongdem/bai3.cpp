#include<iostream>

using namespace std;

// KHAI BAO
/*
const int mod = 1e9 + 7;
const int X = 1e6 + 6;
const int N = 105;
int n, x;
int a[N];
int dp[X];
*/


// SOLUTION
/*
void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i)    cin >> a[i];

    dp[0] = 1;
    for(int i=0; i<x; ++i){
        for(int j=1; j<=n; ++j){
            add(dp[i+a[j]], dp[i]);
        }
    }

    cout << dp[x];
}
*/

const int mod = 1e9 + 7;
int n, x;
int dp[1000005];
int c[1000005];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void review(){
    /*
    Nhận xét, bài toán cho n đồng xu có giá trị c[i]
    Để hỏi tìm số cách để chọn các đồng xu sao cho có tổng bằng x

    Ta duyệt tất cả các trạng thái và cộng lại, nếu bằng x thì đáp án cộng 1

=>  Từ nhận xét trên ta có thể suy ra bài này có thể giải bằng dp

    Ta cần quản lý những gì, để ý với mỗi đồng xu, ta có thể chọn hoặc không chọn.
    Nếu ta quản lý theo kiểu dp[i] la tổng số cách chọn đồng xu có tổng bằng i

=>  [i] la chiều tổng của i
    */

    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;
    for(int i=1; i<=x; ++i){
        for(int j=1; j<=n; ++j){
            if(i - c[j] >= 0){
                add(dp[i], dp[i - c[j]]);
                //dp[i] += dp[i - c[j]];
            }
        }
    }

    cout << dp[x];
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review();
}