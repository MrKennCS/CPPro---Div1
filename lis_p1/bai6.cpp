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
string s;
string t;
int dp[3003][3003];
string res;

void solve(){
    cin >> s >> t;

    n = sz(s);
    m = sz(t);
    s = " " + s;
    t = " " + t;

    dp[0][0] = dp[0][1] = dp[1][0] = 0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i] == t[j])    dp[i][j] = dp[i - 1][j - 1] + 1;
            else                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];
    int u = n;
    int v = m;

    res = string(len, ' ');
    
    while(len){
        if(s[u] == t[v]){
            res[len - 1] = s[u];
            u--;
            v--;
            len--;
        }else{
            if(dp[u][v - 1] > dp[u - 1][v]) v--;
            else                            u--;
        }
    }
    /*
    */


    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
