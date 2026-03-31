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

const int offset = 200;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
int x[2005];
int y[2005];
int trungdiem[405][405];
ll res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> x[i] >> y[i];

    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            trungdiem[x[i] + x[j] + offset][y[i] + y [j] + offset]++;
        }
    }

    for(int i=0; i<=400; ++i){
        for(int j=0; j<=400; ++j){
            if(trungdiem[i][j] > 0){
                //cout << 1.0 * (i - offset) / 2 << " " << 1.0 * (j - offset) / 2 << " " << trungdiem[i][j] << '\n';
                int cnt = trungdiem[i][j];
                res += (cnt - 1) * cnt / 2;
            }
        }
    }

    cout << res;
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}