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
1
4 6
1 2
1 2
1 3
1 3
2 4
1 4

*/

int n, m;
vector<ii> xe(50005, {0, 0});
int l, r, mid, ans;

bool check(int x){
    vector<ii> a;
    for(int i=0; i<x; ++i)  a.pb(xe[i + 1]);

    sort(a.begin(), a.end(), [](const ii& a, const ii& b){
        if(a.fi == b.fi)    return a.se < b.se;
        return a.fi < b.fi;
    });

    int cur = 1;
    int id = 0;

    pqueue<int, vector<int>, greater<int>> pq;

    while(id < x || !pq.empty()){
        if(pq.empty())  cur = max(cur, a[id].fi);

        while(id < x && a[id].fi <= cur){
            pq.push(a[id].se);
            id++;
        }

        int mn = pq.top();
        pq.pop();

        if(cur > n)     return false;
        if(mn < cur)    return false;

        cur++;
    }

    return true;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> xe[i].fi >> xe[i].se;

    l = 1;
    r = m;

    //cout << check(6);

    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else   r = mid - 1;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT

    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    cin >> tc;
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
