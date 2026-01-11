#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
int n;
int dp[125255];
int lim;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    //top down

    cin >> n;

    lim = (n + 1) * n / 2;

    if(lim & 1) cout << 0;
    else{
        lim /= 2;
        dp[1] = 1;
        foru(i, 2, n){
            ford(sum, lim, i){
                add(dp[sum], dp[sum - i]);
                //dp[sum] += dp[sum - i];
            }
            //foru(j, 1, lim) cout << dp[j] << " ";    cout << '\n';
        }
        cout << dp[lim];
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}