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
    if(fopen("TONGNHO.INP", "r")){
        freopen("TONGNHO.INP", "r", stdin);
        freopen("TONGNHO.OUT", "w", stdout);
    }
}

const int LIMM = 100;
const int LIMN = 1e5;
const ll lim = 4e18;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n, m, k;
ll a[LIMN + 5];
int w[LIMN + 5];
vector<vector<ll>> dp(LIMN + 3, vector<ll>(LIMM + 3, lim));

ll tong(ll n){
    ll ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    ll sum = 0;
    ll so = 0;

    for(int i=1; i<=k; ++i){
        sum += a[i];
        so += tong(a[i]);
    }

    w[1] = (so - tong(sum)) / 9;

    for(int i=2; i<=n-k+1; ++i){
        sum += a[i + k - 1] - a[i - 1]; 
        so += tong(a[i + k - 1]) - tong(a[i - 1]);
        w[i] = (so - tong(sum)) / 9;
    }

    // base
    for(int i=0; i<=n; ++i) dp[i][0] = 0;
    
    for(int i=1; i<=n; ++i){
        int mx = min(m, i/k);
        for(int j=1; j<=mx; ++j){
            dp[i][j] = dp[i - 1][j];
            if(i >= k && dp[i - k][j - 1] != lim){
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + w[i - k + 1]);
            }
        }
    }

    cout << dp[n][m];

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    //cin >> tc;
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}

// RATE ?? (?/10)