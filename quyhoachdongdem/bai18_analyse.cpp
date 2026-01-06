// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

#include<bits/stdc++.h>
#define ldb long double
#define db double 
#define unomap unordered_map
#define unoset unordered_set
#define endl '\n'
#define str string
#define strstr stringstream
#define sz(a) (int)a.size()
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define Unique(a) a.resize(unique(all(a)) - a.begin())
#define ull unsigned long long
#define fi first 
#define se second
#define idc cin.ignore()
#define lb lower_bound
#define ub upper_bound
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define rev reverse
#define gcd __gcd
#define pushb push_back
#define popb pop_back
#define pushf push_front
#define popf pop_front
#define emp emplace
#define empb emplace_back
#define mul2x(a, x) a << x
#define div2x(a, x) a >> x
#define lcm(a, b) (a / __gcd(a, b) * b)
#define log_base(x, base) log(x) / log(base)
#define debug cerr << "No errors!", exit(0);
#define forw(i, a, b) for(int i=a; i<=b; ++i)
#define forw2(i, a, b) for(ll i=a; i<=b; ++i)
#define fors(i, a, b) for(int i=a; i>=b; --i)
#define fors2(i, a, b) for(ll i=a; i>=b; --i)
#define pqueue priority_queue
#define sqrt sqrtL
#define i128 __int128
#define popcount __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(x) ((1LL) << (x))
#define want_digit(x) cout << fixed << setprecision(x);
#define excuting_time 1000.0 * clock() / CLOCKS_PER_SEC
#define mapa make_pair

using namespace std;

const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const int limN = 1e6 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random(const ll &L, const ll &R){
    return uniform_int_distribution<ll>(L, R)(rng);
}

// END OF TEMPLATE

ll bpow(ll a, ll e){
    ll r = 1 % MOD;
    while(e > 0){
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

void solve(){
    ll n, M, K;

    if(!(cin >> n >> M >> K)) return;

    if(K == 1){
        cout << bpow(M % MOD, n) % MOD << endl;
        return ;
    }

    vector<ll> sum(n + 1, 0), dp(n + 1, 0);

    dp[1] = M % MOD;
    sum[1] = M % MOD;

    forw2(i, 2, n){
        dp[i] = ((M - 1) % MOD) * sum[i - 1] % MOD;
        int id = i - (K - 1);
        ll sub = 0;
        if(id >= 1) sub = dp[id] % MOD;
        sum[i] = ((M % MOD) * sum[i - 1] % MOD - sub + MOD) % MOD;
    }

    ll all = bpow(M % MOD, n), v = sum[n] % MOD;
    ll ans = (all - v + MOD) % MOD;
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    srand(time(NULL));

    /*
    #define name "test"

    if(fopen(name ".INP", "r")){
        freopen(name ".INP", "r", stdin);
        freopen(name ".OUT", "w", stdout);
    }
    */

    bool testcase = false;

    if(testcase){
        int tc; cin >> tc;
        while(tc--) solve();
    }else   solve();
}
