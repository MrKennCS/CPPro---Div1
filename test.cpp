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

int n, c;
vector<int> x(105, 0);
vector<int> y(105, 0);
vector<ii> L(105, {0, 0});
vector<ii> M(105, {0, 0});
int l, r, mid, ans;

bool check(ll cnt){
    ll C = c;
    for(int i=1; i<=n; ++i){
        ll need = 1ll * cnt * x[i] - y[i];
        if(need <= 0)   continue;

        ll chinhonhat = 2e18;

        // Cách 1: Thử số lượng gói NHỎ từ 0 đến SL (tức L[i].fi)
        for(ll small = 0; small <= L[i].fi; ++small){
            ll rem = max(0ll, need - small * M[i].fi);
            ll large = (rem + L[i].fi - 1) / L[i].fi; // Số gói lớn cần bù
            chinhonhat = min(chinhonhat, small * M[i].se + large * L[i].se);
        }

        // Cách 2: Thử số lượng gói LỚN từ 0 đến SM (tức M[i].fi)
        for(ll large = 0; large <= M[i].fi; ++large){
            ll rem = max(0ll, need - large * L[i].fi);
            ll small = (rem + M[i].fi - 1) / M[i].fi; // Số gói nhỏ cần bù
            chinhonhat = min(chinhonhat, small * M[i].se + large * L[i].se);
        }

        C -= chinhonhat;
        if(C < 0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> c;
    for(int i=1; i<=n; ++i){
        cin >> x[i] >> y[i] >> M[i].fi >> M[i].se >> L[i].fi >> L[i].se;
    }

    
    l = 1;
    r = 1e9;
    while(l <= r){
        //cout << mid << '\n';
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else   r = mid - 1;
    }

    cout << ans;
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
