// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

#define sz(a) (int)a.size()
#define getbit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x) |= (1LL << y))
#define turnof(x, y) ((x) &= ~(1LL << y))
#define daobit(x, y) ((x) ^= (1LL << y))
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^ random_device{}());

ll randInt(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
}

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n, k;
int c[1005][1005];

int trau(int n, int k){
    if(n == 0 && k == 0)    return 0;
    if(n == 0 && k == 1)    return 1;
    if(k > n)               return 0;
    if(k == 0)              return 1;

    if(c[n][k] != 0)    return c[n][k];

    int &res = c[n][k];
    res = (trau(n - 1, k - 1) % mod + trau(n - 1, k) % mod) % mod;

    return res;
}

void init(){
    c[0][0] = 0;
    c[0][1] = 1;
    for(int i=1; i<=1000; ++i){
        for(int j=0; j<=i; ++j){
            if(j == 0)  c[i][j] = 1;
            else        c[i][j] = (c[i - 1][j] % mod + c[i - 1][j - 1] % mod) % mod;
        }
    }
}

void solve(){
    cin >> n >> k;
    cout << trau(n, k) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    cin >> tc;
    //init();
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}

// RATE ?? (?/10)