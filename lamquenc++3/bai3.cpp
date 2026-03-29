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

int m;
int a[3][100005];
ll pre[3][100005];
ll mn;
pair<ll, ll> res;
ll cur;

int id;

void solve(){

    mn = 1e18 + 7;

    cin >> m;
    for(int i=1; i<=2; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }

    for(int i=1; i<=m; ++i){
        //cout << i << " " << pre[1][i] - pre[1][0] + pre[2][m] - pre[2][i - 1] << '\n';

        //cout << pre[1][m] - pre[1][i] << " " << pre[2][i - 1] - pre[2][0] << '\n';

        cur = max(pre[1][m] - pre[1][i], pre[2][i - 1] - pre[2][0]);
        if(mn > cur){
            mn = cur;
            res.fi = pre[1][m] - pre[1][i];
            res.se = pre[2][i - 1] - pre[2][0];
        }
    }

    //cout << "CUR: " << cur << '\n';
    //cout << "RES: " << res.fi << " " << res.se << '\n';
    cout << max(res.fi, res.se) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> tc;
    while(tc--)  solve();
}
