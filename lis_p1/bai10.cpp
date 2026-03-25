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

int n;
string s;
string t;
string res;
int dp[2002][2002];

string rev(string x){
    string ans = "";
    for(int i=sz(x)-1; i>=0; --i)   ans += x[i];
    return ans;
}

void solve(){
    cin >> s;

    n = sz(s);
    t = rev(s);

    s = " " + s;
    t = " " + t;

    //cout << s << " " << t;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i] == t[j])    dp[i][j] = dp[i - 1][j - 1] + 1;
            else                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //cout << dp[n][n];
    int len = dp[n][n];
    int u = n;
    int v = n;

    res = string(len, ' ');
    
    while(len){
        if(s[u] == t[v]){
            res[len - 1] = s[u];
            u--;
            v--;
            len--;
        }else{
            if(dp[u - 1][v] > dp[u][v - 1]) u--;
            else                            v--;
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
