#include<iostream>
#include<unordered_map>

using namespace std;

int n, x;
int c[105];
int dp[1000009];
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> c[i];

    dp[0] = 1;
    for(int i=1; i<=x; ++i){
        for(int j=1; j<=n; ++j){
            int tmp;
            if(i - c[j] < 0)    tmp = 0;
            else                tmp =  max(dp[i-c[j]], 0);
            add(dp[i], tmp);
        }
    }

    cout << dp[x];

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}