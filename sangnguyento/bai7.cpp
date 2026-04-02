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

int a, b;
bool isPrime[200005];

void INPUT(){
    cin >> a >> b;
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

bool snt(ll n){
    if(n <= 2)  return (n == 2);
    for(int i=1; i<=100; ++i){
        ll x = rand(2, n - 1);
        if(pow(x, n - 1, n) != 1)  return false;
    }
    return true;
}

void trau(){
    for(int i=a; i<=b; ++i){
        if(snt(i))  cout << i << '\n';
    }
    return ;
}

void chuan(){
    // SANG SNT
    isPrime[0] = isPrime[1] = 1;
    for(int i=2; 1ll*i*i<=200000; ++i){
        if(isPrime[i] == 0){
            for(int j=i*i; j<=200000; j+=i){
                isPrime[j] = 1;
            }
        }
    }

    for(int i=a; i<=b; ++i){
        if(isPrime[i] == 0) cout << i << '\n';
    }

}

void solve(){
    /*
    */
    chuan();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();
    INPUT();
    // Bat dau do
    /*
    */
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    while(tc--)  solve();

    // Dung do
    /*
    */
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
