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
#define foru(i, a, b)   for(int i=a; i<=b; ++i)
#define ford(i, a, b)   for(int i=a; i>=b; --i)
#define foruc(i, a, b, c)   for(int i=a; i<=b; i+=c)
#define fordc(i, a, b, c)   for(int i=a; i>=b; i-=c)

#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound // >=
#define ub upper_bound // >

const int mod = 1e9 + 7;
const int base = 5000;
int tc = 1;

/*

*/

int n, x;
int t[105];
int dp[2][105][5005 + base];
int res;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void pre_calc(){
    sort(t + 1, t + n + 1);
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> t[i];

    pre_calc();

    memset(dp, 0, sizeof(dp));
    dp[0][0][base] = 1;

    

    for(int i=0; i<n; ++i){
        for(int j=0; j<=n; ++j){
            for(int z=0; z<=x+base; ++z){
                if(dp[i & 1][j][z] > 0){
                    int nx = (i + 1) & 1;
                        add(dp[nx][j][z],                    dp[i & 1][j][z]);
                    if(z >= t[i + 1]){
                        add(dp[nx][j + 1][z - t[i + 1]],     dp[i & 1][j][z]);
                    }
                        add(dp[nx][j][z],                    (1ll * j * dp[i & 1][j][z]) % mod);
                    if(j >= 1 && (z + t[i + 1] <= x + base)){
                        add(dp[nx][j - 1][z + t[i + 1]],     (1ll * j * dp[i & 1][j][z]) % mod);
                    }
                }
            }
        }
        for(int j=0; j<=n; ++j){
            for(int z=0; z<=x+base; ++z){
                dp[i & 1][j][z] = 0;
            }
        }
    }

    for(int i=base; i<=x + base; ++i) add(res, dp[n & 1][0][i]);

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
