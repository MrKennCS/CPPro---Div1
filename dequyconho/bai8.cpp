#include<iostream>
#include<cstring>

using namespace std;

int n;
int dp[1000009];

int trau(int sum){
    if(dp[sum] != -1)   return dp[sum];

    int &res = dp[sum];
    res = 0;

    int tmp = sum;
    int num = 0;
    while(tmp){
        num = max(num, tmp % 10);
        tmp /= 10;
    }

    res = trau(sum - num) + 1;

    return res;
}

void solve(){
    /*
    Bai toan yeu cau:
    Tim so cach tru so n (voi so tru la mot chu so bat ky cua n) ve bang khong ngan nhat

    Nhan xet: Ta can tru so n mot luong la nhieu nhat de bien so n ve thanh 0
    Trong 10 chu so tu 0 -> 9
    Ta uu tien chon nhung chu so co gia tri cao nhat cua n de tru
    
    
->  Voi moi n, ta tru di mot luong la max(x1, x2, x3, ..., xi) (xn la chu so thu i cua so n)

    Goi dp[i] la so lan tru it nhat de bien i thanh 0

    Voi moi i, ta tim chu so lon nhat trong i roi tiep tuc voi bai toan i - xi (xi la chu so lon nhat trong i)

    BASE:
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    ...
    dp[8] = 1;
    dp[9] = 1;
    */
    cin >> n;

    //TH BASE
    for(int i=0; i<=9; ++i) dp[i] = 1;

    for(int i=10; i<=n; ++i){
        int num = 0;
        int tmp = i;
        while(tmp){
            num = max(num, tmp%10);
            tmp /= 10;
        }
        dp[i] = dp[i-num] + 1;
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();

    cin >> n;

    memset(dp, -1, sizeof(dp));

    for(int i=0; i<=9; ++i) dp[i] = 1;
    
    cout << trau(n);
}