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

void solve1(){
    int a, b;
    cin >> n;
    vector<ii> val;
    for(int i=1; i<=n; ++i){
        cin >> a >> b;
        val.pb({a, 1});
        val.pb({b + 1, -1});
    }
    sort(val.begin(), val.end());

    int res = 0;
    int cur = 0;
    for(int i=0; i<sz(val); ++i){
        cur += val[i].se;
        res = max(res, cur);
    }
    cout << res;

}

void solve(){
    cin >> n;

    int res = 0;
    int a[n + 4];
    int b[n + 4];

    for(int i=1; i<=n; ++i) cin >> a[i] >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for(int i=1; i<=n; ++i){
        int lower = lb(b + 1, b + n + 1, a[i]) - b - 1;
        res = max(res, i - lower);
        //cout << i << " " << lower << " " << i - lower << '\n';
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
    
    while(tc--)  solve1();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
