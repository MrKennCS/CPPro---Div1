#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
int n;
int dp[505][125255 + 505];
int tong;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n;

    dp[0][0] = 1;

    tong = n * (1 + n) / 2;

    if(tong & 1){
        cout << 0;
        return ;
    }


    for(int i=0; i<n; ++i){
        for(int sum=0; sum <= tong; ++sum){
            add(dp[i + 1][sum + i + 1], dp[i][sum]);
            add(dp[i + 1][sum], dp[i][sum]);
        }
    }
    tong /= 2;

    cout << dp[n][tong] / 2 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    freopen("test.INP", "r", stdin);
    freopen("test.OUT", "w", stdout);
    solve();
}
