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
    abcabcabc...
    acbacbacb
    bacbacbac
    bcabcabca
    cabcabcab
    cbacbacba
*/

int n, m;
string mai;
string s;
vector<string> t;
int l, r;
int si;
int cur;

void solve(){
    cin >> n >> m;
    cin >> mai;
    mai = " " + mai;

    while(m--){
        s = "";
        t = vector<string>(6, "");
        cin >> l >> r;
        for(int i=l; i<=r; ++i) s += mai[i];

        si = r - l + 1;

        // so lan can add si / 3 + 1

        for(int i=1; i<=si / 3 + 1; ++i)    t[0] += "abc";
        for(int i=1; i<=si / 3 + 1; ++i)    t[1] += "acb";
        for(int i=1; i<=si / 3 + 1; ++i)    t[2] += "bac";
        for(int i=1; i<=si / 3 + 1; ++i)    t[3] += "bca";
        for(int i=1; i<=si / 3 + 1; ++i)    t[4] += "cab";
        for(int i=1; i<=si / 3 + 1; ++i)    t[5] += "cba";

        for(int i=1; i<=si; ++i){
            cout << s[i]
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
