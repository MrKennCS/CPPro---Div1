#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
const int SUM = 500 * 500 + 510;
int n;
int dp[505][SUM];
int lim;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n;

    dp[0][0] = 1;
    lim = n * (n + 1) / 2;

    if(lim & 1){
        cout << 0;
        return ;
    }

    lim /= 2;

    for(int i=0; i<n; ++i){
        for(int sum=0; sum<=lim; ++sum){
            if(dp[i][sum] > 0){
                add(dp[i + 1][sum + i + 1], dp[i][sum]);
                add(dp[i + 1][sum], dp[i][sum]);
            }
        }
    }

    cout << dp[n][lim] / 2;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}