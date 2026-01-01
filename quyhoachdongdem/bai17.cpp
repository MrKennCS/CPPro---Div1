#include<iostream>

using namespace std;

// SOLUTION
/*
const int mod = 1e9 + 7;
int n, k;
int a[2003];
int dp[2003][2003];
int res;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void sub_1_va_2(){
    cin >> n >> k;

    if(k == 2){
        for(int i=1; i<=n; ++i){
            for(int j=i; j<=n; ++j){
                if(j % i == 0)  res++;
            }
        }
    }else if(k == 3){
        for(int i=1; i<=n; ++i){
            for(int j=i; j<=n; ++j){
                for(int k=j; k<=n; ++k){
                    if(j % i == 0 && k % j == 0)    res++;
                }
            }
        }
    }
    cout << res;
}

void solve(){
    cin >> n >> k;

    for(int val=1; val<=k; ++val)   dp[val][0] = val;
    for(int i=1; i<=k; ++i){
        for(int j=1; j<=n; ++j){
            if(i == 1)  dp[i][j] = 1;
            else{
                for(int num=j; num<=n; num += j){
                    add(dp[i][num], dp[i-1][j]);
                    //dp[i][num] += dp[i-1][j];
                }
            }
        }
    }

    for(int i=1; i<=n; ++i) add(res, dp[k][i]);
    cout << res;
}
*/

// EXPLAIN
/*
    Đề bài yêu cầu tìm số dãy số có độ dài k và dãy thỏa điều kiện a[i] % a[i-1] == 0 với mọi i>=2

    * ĐỀ BÀI YÊU CẦU ĐẾM SỐ DÃY THỎA MÃN

    Như vậy ta sẽ đếm số trạng thái thảo mãn, ta cần quản lý những điều sau:
        + Trạng thái hiện tại [i]
        + Giá trị ở vị trí i

    Với mỗi i, ta có các trạng thái:

    TH1: val = 1
->  (i, 1) -> (i + 1, [1 -> n]); 

    TH2: val = 2
->  (i, 2) -> (i + 1, 2)

    TH3: val = 3
->  (i, 3) -> (i + 1, 3)

    ...

    THn: val = n
->  (i, n) -> (i + 1, [x % n == 0, n < x <= lim])

    BASE:
    dp[1][val: 1 -> n] = 1
*/

/*
    XÂY MẢNG THÌ CẦN YẾU TỐ ĐỘ DÀI, HƠN NỮA ĐỀ CŨNG YÊU CẦU ĐIỀU KIỆN ĐỘ DÀI K
->  dp phải có một chiều cho độ dài [i]

->  Với để xây dự dãy ở độ dài thứ i, ta phải biết được phần tử thứ i-1
=>  dp phải có thêm một chiều cho giá trị thứ i-1

    Gọi dp[i][j] là số dãy có độ dài bằng i và phần tử cuối cùng bằng j

    BASE: dp[1][x: 1->n] = 1

    Công thức:

    dp[i][j] = dp[i-1][num] với num là mọi ước của j mà <= n
*/


// REVIEW1
/*
void review(){
    cin >> n >> k;

    for(int i=1; i<=n; ++i) dp[1][i] = 1;
    for(int i=1; i<=n; ++i) dp[0][i] = i;
    for(int i=1; i<=k; ++i) dp[i][0] = i;

    for(int i=1; i<k; ++i){
        for(int j=1; j<=n; ++j){
            for(int boi=j; boi<=n; boi+=j){
                add(dp[i+1][boi], dp[i][j]);
            }
        }
    }

    for(int  i=1; i<=n; ++i) add(res, dp[k][i]);
    cout << res;
}
*/

const int mod = 1e9 + 7;
const int N = 2e3 + 5;
int n, k;
int dp[N][N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void review2(){
    cin >> n >> k;

    for(int i=1; i<=n; ++i) dp[1][i] = 1;
    
    for(int i=1; i<k; ++i){
        for(int val=1; val<=n; ++val){
            for(int boi=val; boi<=n; boi+=val){
                add(dp[i + 1][boi], dp[i][val]);
            }
        }
    }

    int res = 0;
    for(int i=1; i<=n; ++i){
        //cout << dp[k][i] << " ";
        add(res, dp[k][i]);

    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //review();
    review2();

}