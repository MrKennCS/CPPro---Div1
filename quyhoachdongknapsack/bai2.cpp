#include<iostream>

using namespace std;

int n, s;
int w[103];
int v[103];
long long dp[100005];

void solve(){
    cin >> n >> s;
    for(int i=1; i<=n; ++i) cin >> w[i] >> v[i];

    for(int i=1; i<=n; ++i){
        for(int j=s; j>=w[i]; --j){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    for(int i=s; i>=1; --i) if(dp[i] != 0){
        cout << dp[i];
        return ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}