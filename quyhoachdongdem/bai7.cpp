#include<iostream>
#include<cstring>

using namespace std;



const int mod = 1e9 + 7;
const int N = 6e2 + 5;
int n, t, a, b;
int dp[2][N][N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    //if(x < mod)     x += mod;
}

void review(){
    cin >> n >> t >> a >> b;

    dp[0][0][0] = 1;
    for(int j=0; j<t; ++j){
        int nx = (j + 1) & 1;
        memset(dp[nx], 0, sizeof(dp[nx]));
        for(int cnt_a=0; cnt_a<=min(n, j); ++cnt_a){
            for(int cnt_b=0; cnt_b<=min(n - cnt_a, j); ++cnt_b){
                if(dp[j & 1][cnt_a][cnt_b] > 0){
                    /*
                    dp[j + 1][cnt_a + 1][cnt_b] += dp[j][cnt_a][cnt_b] * (n - cnt_a - cnt_b);
                    if(cnt_a >= 1)  dp[j + 1][cnt_a - 1][cnt_b + 1] += dp[j][cnt_a][cnt_b] * cnt_a;
                    if(cnt_b >= 1)  dp[j + 1][cnt_a][cnt_b - 1] += dp[j][cnt_a][cnt_b] * cnt_b;
                    */
                    add(dp[nx][cnt_a + 1][cnt_b], (1LL * dp[j & 1][cnt_a][cnt_b] * (n - cnt_a - cnt_b)) % mod);
                    if(cnt_a >= 1)  add(dp[nx][cnt_a - 1][cnt_b + 1], (1LL * dp[j & 1][cnt_a][cnt_b] * cnt_a) % mod);
                    if(cnt_b >= 1)  add(dp[nx][cnt_a][cnt_b - 1], (1LL * dp[j & 1][cnt_a][cnt_b] * cnt_b) % mod);
                }
            }
        }
    }

    cout << dp[t & 1][a][b];

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review();
}