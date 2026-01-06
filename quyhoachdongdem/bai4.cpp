#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
const int limN = 105;
const int limX = 1e6 + 5;
int n, x;
int c[limN];
int dp[limX];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;
    //foru(i, 0, x)   cout << i << " ";   cout << '\n';
    foru(i, 1, n){
        foru(sum, 1, x){
            if(sum - c[i] >= 0) add(dp[sum], dp[sum - c[i]]);
        }
        //foru(i, 0, x)   cout << dp[i] << " ";
        //cout << '\n';
    }
    cout << dp[x];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}