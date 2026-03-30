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
int l, r;
int cnt;
string s;
string pattern[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
vector<string> gen(6, "");
vector<vector<ll>> pre(6, vector<ll>(200005, 0));
ll res;

void solve(){
    cin >> n >> m;
    cin >> s;

    while(cnt <= n){
        gen[0] += pattern[0];
        gen[1] += pattern[1];
        gen[2] += pattern[2];
        gen[3] += pattern[3];
        gen[4] += pattern[4];
        gen[5] += pattern[5];s
        cnt += 3;
    }



    for(int pt=0; pt<6; ++pt){
        for(int i=0; i<sz(s); ++i){
            pre[pt][i + 1] = pre[pt][i] + (s[i] != gen[pt][i]);
        }
    }
    /*
    */

    while(m--){
        cin >> l >> r;

        res = 1e9 + 7;

        for(int pt=0; pt<6; ++pt){
            res = min(pre[pt][r] - pre[pt][l - 1], res);
        }
        /*
        for(int pt=0; pt<6; ++pt){
            res = min(pre[pt][r] - pre[pt][l - 1], res);
        }
        */

        cout << res << '\n';
    }
    /*
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
