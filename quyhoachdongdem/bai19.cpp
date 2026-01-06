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

int n, k;
int a[N];

/*
    Goi dp[i] la so cach chia thoa man
*/

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

ll bpow(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1)   r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

void sub1(){
    cout << bpow(2, n - 1);
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    if(k == 1)  sub1();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
