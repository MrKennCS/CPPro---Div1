// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set

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

int n, m;
int l[100005];
ll res;
int last;
int a, b;

void solve(){
    res = 0;
    last = 0;

    cin >> n >> m;

    for(int i=1; i<=n; ++i) l[i] = 0;

    for(int i=1; i<=m; ++i){
        cin >> a >> b;
        if(a > b)   swap(a, b);
        l[b] = max(l[b], a);
    }

    for(int i=1; i<=n; ++i){
        //cout << i << " " << l[i] << '\n';
        if(l[i] != 0){
            res += (i - l[i]);
            last = i;
        }else{
            if(last == 0)   res += i;
            else            res += (i - last + 1);
        }
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> tc;
    while(tc--)  solve();
}
