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

const int mod = 14062008;
const int limN = 1e5 + 5;
int tc = 1;

int n, k;
bool hu[limN];
int dp[limN];
int tmp;

void solve(){
    cin >> n >> k;
    for(int i=1; i<=k; ++i){
        cin >> tmp;
        hu[tmp] = true;
    }

    if(!hu[1])  dp[1] = 1;
    if(!hu[2])  dp[2] = 1;

    for(int i=3; i<=n; ++i){
        if(hu[i]){
            dp[i] = 0;
            continue ;
        }
        dp[i] = (dp[i-1] % mod + dp[i-2] % mod) % mod;
    }

    
    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
