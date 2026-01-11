#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
const int limN = 1e5 + 3;
const int limK = 1e3 + 3;
int n, k;
int h[limK];
int dp[limN];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> k;
    foru(i, 1, k)   cin >> h[i];

    dp[0] = 1;
    foru(c, 0, n){
        foru(i, 0, k - 1){
            if(dp[c] > 0){
                dp[c + h[i + 1]] += dp[c];
            }
        }
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}