#include<iostream>

using namespace std;

int h, w;
int a[1005][1005];
int dp[1005][1005];
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> h >> w;
    dp[0][1] = 1;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            char tmp;   cin >> tmp;
            if(tmp != '#'){
                add(dp[i][j], dp[i-1][j]);
                add(dp[i][j], dp[i][j-1]);
                //dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout << dp[h][w];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}