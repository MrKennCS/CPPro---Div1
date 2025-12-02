#include<iostream>

using namespace std;

const int mod = 14062008;
const int N = 1e5 + 5;
int n, k;
int a[N];
int dp[N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> a[i];

    int pos = 1;
    
    dp[1] = 1;
    for(int i=1; i<=n-1; ++i){
        if(i == a[pos]){
            pos++;
            continue;
        }
        add(dp[i+1], dp[i]);
        add(dp[i+2], dp[i]);
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}