#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
int n, k;
int a[lim];
int dp[lim];
int pos;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

int get(int l, int r){
    if(l > r)   return 0;
    if(l == 0)  return dp[r];
    return (dp[r] - dp[l - 1] + mod) % mod;
}

void solve(){
    cin >> n;
    foru(i, 1, n)   cin >> a[i];
    cin >> k;

    dp[0] = 1;
    dp[1] = 2;
    pos = 1;

    foru(i, 2, n){
        if(a[i] != a[i-1])  pos = i;
        dp[i] = get(max(pos - 1, i - k), i - 1);
        add(dp[i], dp[i - 1]);
        //sum[i] = dp[i] + sum[i - 1];
    }
    //for(int i=1; i<=n; ++i) cout << dp[i] << " ";   cout << '\n';
    cout << get(n, n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}