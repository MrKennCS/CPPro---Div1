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

const int inf = 2e9;
const ll infll = 4e18;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
int h[20];
int w[20][20];
int Pow[20];
vector<int> s(20, 1);
ll res = infll;

void solve(){
    cin >> n;

    Pow[0] = 1;
    for(int i=1; i<=n; ++i){
        cin >> h[i];
        Pow[i] = Pow[i - 1] * 2;
    }
    
    for(int i=1; i<=n-1; ++i){
        for(int j=i+1; j<=n; ++j){
            cin >> w[i][j];
        }
    }

    for(int mask=0; mask<Pow[n]; ++mask){   
        ll cur = 0;

        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                int mot = getbit(mask, i);
                int hai = getbit(mask, j);
                if(i == j){
                    cur += h[i + 1] * (mot ? 1 : -1);
                }else{
                    cur += w[i + 1][j + 1] * (mot ? 1 : -1) * (hai ? 1 : -1);
                }
            }
        }

        res = min(res, cur);
    }

    cout << res;
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