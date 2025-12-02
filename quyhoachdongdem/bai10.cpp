#include<iostream>
#define ull unsigned long long
using namespace std;

int n, k;
ull dp[10005];

ull get(int l, int r){
    if(l == 0)  return dp[r];
    return dp[r] - dp[l-1];
}

void solve(){
    cin >> n >> k;
   
    for(int i=1; i<k; ++i){
        dp[i] = (1LL << i);
        dp[i] += dp[i-1];
    }
    dp[k] = (1ULL << k) - 1;
    dp[k] += dp[k-1];

    for(int i=k+1; i<=n; ++i){
        dp[i] = get(i-k, i-1);
        dp[i] += dp[i-1];
    }

    /*
    i = 4

    l = i - 1 - k = 4 - 1 - 2 = 1

    2 5 10 18
    2 3 5 8
    */

    //for(int i=1; i<=n; ++i) cout << dp[i] << " ";   cout << '\n';

    cout << (1ULL << n) - (dp[n] - dp[n-1]);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}