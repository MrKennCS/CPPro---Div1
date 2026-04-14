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
#define turnof(x, y) ((x) & ~(1LL << y))
#define daobit(x, y) ((x) ^ (1LL << y))
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

random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution<ll> dist(1, 1e18);

ll rand(ll l, ll r){
    ll res = 0;
    for(int i=0; i<4; ++i){
        res = (res << 15) ^ (dist(gen) & ((1ll << 15) - 1ll)); 
    }
    return l + res % (r - l + 1);
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

bool snt(ll n){
    if(n <= 2)  return (n == 2);
    for(int i=1; i<=100; ++i){
        ll x = rand(2, n - 1);
        if(pow(x, n - 1, n) != 1)   return false;
    }
    return true;
}

void solve(){
    ll n;   cin >> n;
    for(int i=1; i<=n; ++i) cout << i << " " << snt(i) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //file();

    // INPUT

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
