#include<iostream>
#include<cstring>
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

//const int offset = 2500;
const int mod = 1e9 + 7;
int n, k;
int dp[55][55][5005];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x %= mod;
}

void solve(){
/*

*/

    cin >> n >> k;
    //memset(dp, 0, sizeof(dp));
    dp[0][0][n*n] = 1;
    int lim = 2*n*n;
    const int offset = n*n;

    //cout << lim << '\n';

    for(int i=0; i<n; ++i){
        for(int cnt=0; cnt<=n/2; ++cnt){
            for(int sum=0; sum<=lim; ++sum){
                if(dp[i][cnt][sum] > 0){
                    //dp[i+1][cnt-1][sum+2*(i+1)] += dp[i][cnt][sum];
                    cout << "GAY\n";
                    dp[i+1][cnt][sum] += dp[i][cnt][sum];
                    dp[i+1][cnt+1][sum-2*(i+1)] += dp[i][cnt][sum];
                    
                    dp[i+1][cnt][sum] %= mod;
                    dp[i+1][cnt+1][sum-2*(i+1)] %= mod;

                    cout << i+1 << " " << cnt << " " << sum << ": " <<  dp[i+1][cnt][sum] << '\n';
                    cout << i+1 << " " << cnt+1 << " " << sum-(i+1)*2 << ": " <<  dp[i+1][cnt+1][sum-(i+1)*2] << '\n';
                    
                    if(cnt >= 1){
                        cout << "GAY1\n";
                        dp[i+1][cnt-1][sum+2*(i+1)] += (1LL*dp[i][cnt][sum]*cnt*cnt)%mod;
                        dp[i+1][cnt][sum] += (dp[i][cnt][sum]*cnt*2)%mod;

                        dp[i+1][cnt-1][sum+2*(i+1)] %= mod;
                        dp[i+1][cnt][sum] %= mod;

                        cout << i+1 << " " << cnt << " " << sum << ": " <<  dp[i+1][cnt][sum] << '\n';
                        cout << i+1 << " " << cnt-1 << " " << sum-(i+1)*2 << ": " <<  dp[i+1][cnt-1][sum+(i+1)*2] << '\n';
                    }
                }
            }
        }
    }

    cout << dp[n][0][k+n*n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
