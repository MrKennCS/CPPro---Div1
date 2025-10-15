#include<iostream>
#include<cstring>

using namespace std;

int dp[1005][1005];
// dp[n][k] la cach chon k trong n duoc cho
const int mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    int q;  cin >> q;

    dp[0][0] = 1;

    for(int i=0; i<1000; ++i){
        for(int j=0; j<=i; ++j){
            if(dp[i][j] == 0)   continue;

            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
        }
    }   

    while(q--){
        int n, k;   cin >> n >> k;
        cout << dp[n][k] << '\n';
    }

    /*

    TH1: neu chon i + 1

    dp[i+1][j+1] += dp[i][j];

    TH2: neu khong chon i + 1

    dp[i+1][j+1] += dp[i][j+1]
    */
}