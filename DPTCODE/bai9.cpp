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
ll s;
int c[40];
int res;

// SUB1
ll sum;


void sub1(){
    for(int i=1; i<=n; ++i){
        if(sum - c[i] == s) res++;
    }
    cout << res;
}

void sub2(){
    int dp[n + 3][m + 3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;

    

    cout << dp[n][m];
}

void sub3(){

}

void solve(){
    cin >> n >> m >> s;
    for(int i=1; i<=n; ++i){
        cin >> c[i];

        // SUB1
        sum += c[i];
    }

    if(n - 1 == m && n <= 18)   sub2();
    else if(n <= 18)            sub2();
    else                        sub3();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
