#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
int n, t, a, b;
int dp[2][603][603];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
/*
int trau(int i, int cnt_a, int cnt_b){
    //cout << i << " " << cnt_a << " "  << cnt_b << '\n';
    if(i < 0 || cnt_a < 0 || cnt_b < 0) return 0;
    if(cnt_a + cnt_b > n)               return 0;

    if(dp[i][cnt_a][cnt_b] != 0){
        //cout << "(" << i << ", " << cnt_a << ", " << cnt_b << "): " << dp[i][cnt_a][cnt_b] << '\n';
        return dp[i][cnt_a][cnt_b];
    }

    int &res = dp[i][cnt_a][cnt_b];
    res = 0;

    add(res, 1LL * trau(i - 1, cnt_a - 1, cnt_b) * (n - cnt_a - cnt_b + 1) % mod);
    add(res, 1LL * trau(i - 1, cnt_a + 1, cnt_b - 1) * (cnt_a + 1) % mod);
    add(res, 1LL * trau(i - 1, cnt_a, cnt_b + 1) * (cnt_b + 1) % mod);

    return res;
}
*/

void solve(){
    cin >> n >> t >> a >> b;

    dp[0][0][0] = 1;
    
    foru(i, 0, t - 1){
        int nx = (i + 1) & 1;
        memset(dp[nx], 0, sizeof(dp[nx]));
        foru(cnt_a, 0, min(n, i)){
            foru(cnt_b, 0, min(n - cnt_a, i)){
                if(dp[i & 1][cnt_a][cnt_b] > 0){
                    add(dp[nx][cnt_a + 1][cnt_b], 1LL * dp[i & 1][cnt_a][cnt_b] * (n - cnt_a - cnt_b) % mod);
                    if(cnt_a >= 1)  add(dp[nx][cnt_a - 1][cnt_b + 1], 1LL * dp[i & 1][cnt_a][cnt_b] * cnt_a % mod);
                    if(cnt_b >= 1)  add(dp[nx][cnt_a][cnt_b - 1], 1LL * dp[i & 1][cnt_a][cnt_b] * cnt_b % mod);
                }
            }
        }
    }

    cout << dp[t & 1][a][b];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}