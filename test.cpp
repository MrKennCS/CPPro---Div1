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
    if(fopen("LAB.INP", "r")){
        freopen("LAB.INP", "r", stdin);
        freopen("LAB.OUT", "w", stdout);
    }
}

const int LIMN = 200005;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
int a[LIMN];
int pos[LIMN];
bool check[LIMN];
int nx[LIMN];
int mn;
int mx;
int res;
int u, v, l, r;
int cur;

int nxt(int x){
    if(nx[x] == x)  return x;
    return nx[x] = nxt(nx[x]);
}

void solve(){
    cin >> n;

    foru(i, 0, n - 1){
        cin >> a[i];
        pos[a[i]] = i;
        nx[i] = i;
    }
    
    nx[n] = n;

    mn = 1;
    mx = n;
    res = 0;

    while(mn <= mx){
        while(mn <= n && check[mn]) mn++;
        while(mx >= 1 && check[mx]) mx--;

        if(mn > mx) break;

        u = pos[mn];
        v = pos[mx];

        l = min(u, v);
        r = max(u, v);

        cur = nxt(l);

        while(cur <= r){
            check[a[cur]] = 1;
            nx[cur] = nxt(cur + 1);
            cur = nxt(cur);
        }

        res++;
    }

    cout << res << '\n';
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
