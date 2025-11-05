#include<iostream>
#include<cstring>

using namespace std;

int n;
int dp[100009];
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int trau(int pos){
    if(dp[pos] != -1)   return dp[pos];

    int &res = dp[pos];
    res = 0;

    add(res, trau(pos - 1));
    add(res, trau(pos - 2));

    return res;
}

void solve(){
    cin >> n;
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; ++i){
        add(dp[i], dp[i-1]);
        add(dp[i], dp[i-2]);
    }

    cout << dp[n];
    /*
    Ta co 2 * i o, voi moi o, ta co 2 truong hop:
    TH1: xep o gach ngang
    TH2: xep o gach doc

    CHU Y: ta xet hang 2, ta se khong the xet truong hop TH2 do se vuot ra khoi bang

    TH1: Hang 1:

        TH1.1: Ngang
        -> Nhan xet mot chut neu ta dat o ngang, ta buoc phai dat them mot thanh ngang o hang 2 (bat buoc)
        -> Chiem 2 o

    Ta co, bai toan thu n phu thuoc vao bai toan thu n-1
->  Duyet for tu 1 -> n

    Goi dp[i] la so cach dat gach xet den vi tri i
->  Voi moi i, ta co 2 truong hop:
    TH1: Gach ngang
->  Chiem 2 o
->  dp[i] += dp[i-2];

    TH2: Gach doc
->  CHiem 1 o
->  dp[i] += dp[i-1]

    Vay voi moi i, ta tinh tong 2 truong hop dp[i-1] va dp[i-2]

->  dp[i] = dp[i-1] + dp[i-2]
    BASE:
    dp[0] = 1
    dp[1] = 1
    
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();


    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 1;
    cout << trau(n);
}