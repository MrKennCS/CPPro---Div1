// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define ii pair<int, int>
#define getbit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x) | (1LL << y))
#define turnof(x, y) ((x) ^ (1LL << y))

#define fi first 
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound // >=
#define ub upper_bound // >

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int tc = 1;

int n, m, k;
int dp[N];
int bp[N];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)   ans = (1LL * ans * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    cin >> n >> m >> k;

    if(k == 1){
        cout << 1LL * binpow(2, n - 1) * m % mod;
        return ;
    }

    dp[k] = m;

    bp[0] = 1;
    for(int i=1; i<=n; ++i){
        bp[i] = 1LL * bp[i - 1] * m % mod;
    }

    for(int i=k+1; i<=n; ++i){
        dp[i] = (1LL * dp[i-1] * m % mod + (1LL * bp[i - k] - dp[i - k] + mod) * (m - 1) % mod) % mod;
        //add(dp[i], 1LL * dp[i-1] * m % mod);
        //add(dp[i], (1LL * binpow(m, i - k) - dp[i - k] + mod) * (m - 1) % mod);
    }

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
