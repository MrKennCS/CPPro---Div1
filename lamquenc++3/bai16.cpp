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
int x, y;

bool corner(int x, int y){
    if      (x == 1 && y == 1)  return true;
    else if (x == 1 && y == m)  return true;
    else if (x == n && y == 1)  return true;
    else if (x == n && y == m)  return true;
    return false;
}

bool edge(int x, int y){
    if(x == 1)      return true;
    else if(x == n) return true;
    else if(y == 1) return true;
    else if(y == m) return true;
    return false;
}

void solve(){
    cin >> n >> m;
    cin >> x >> y;

    if(corner(x, y))    cout << 3;
    else if(edge(x, y)) cout << 5;
    else                cout << 8;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
