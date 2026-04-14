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
int val;
map<int, int> cnt;
vector<int> a, b;
int Pow[30];
int res = 0;

void solve(){
    cin >> n;
    
    Pow[0] = 1;
    for(int i=1; i<=n; ++i){
        cin >> val;
        Pow[i] = Pow[i - 1] * 3;
        if(i <= n / 2)  a.pb(val);
        else            b.pb(val);
    }

    for(int mask=0; mask<Pow[sz(a)]; ++mask){
        int suma = 0;
        int sumb = 0;
        int tmp = mask;
        for(int i=0; i<sz(a); ++i){
            if(tmp % 3 == 0)    continue;
            else if(tmp % 3 == 1)   suma += a[i];
            else                    sumb += a[i];
            tmp /= 3;
        }
        cnt[suma - sumb] = max(cnt[suma - sumb], suma);
        if(suma == sumb)    res = max(res, suma);
    }

    for(int mask=0; mask<Pow[sz(b)]; ++mask){
        int suma = 0;
        int sumb = 0;
        int tmp = mask;
        for(int i=0; i<sz(b); ++i){
            if(tmp % 3 == 0)    continue;
            else if(tmp % 3 == 1)   suma += b[i];
            else                    sumb += b[i];
            tmp /= 3;
        }
        res = max(res, cnt[sumb - suma]);
        if(sumb == suma)    res = max(res, sumb);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

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
