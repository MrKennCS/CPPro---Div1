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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r){
    assert(l <= r);
    return l + rd() % (r - l + 1);
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

int n;
int a[100006];
int bcln = 1;
int cur;
ll res = 1;

ll gcd(ll a, ll b){
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b) * b);
}

ll mul(ll a, ll b, ll mod){
    ll ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

ll pow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1)   ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return ans;
}

void solve(){
    for(int i=1; i<=n; ++i){
        bcln %= mod;
        bcln = lcm(bcln, a[i]);
    }

    vector<pair<ll, int>> val;
    //cout << "BCLN: " << bcln << '\n';
    for(ll i=2; i*i<=bcln; ++i){
        if(bcln % i == 0){
            cur = 0;
            while(bcln % i == 0){
                cur++;
                bcln /= i;
            }
            //val.pb()
            if(cur & 1) cur++;
            val.pb({i, cur});
        }
    }
    if(bcln > 1)    val.pb({bcln, 2});

    for(int i=0; i<sz(val); ++i){
        res = mul(res, pow(val[i].fi, val[i].se, mod), mod);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
