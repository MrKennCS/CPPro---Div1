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

const int mod = 1e9 + 7;
int tc = 1;

/*
3 1
1 2 3
4 5 6
7 8 9
-1


*/

int n, q;
vector<vector<int>> a(103, vector<int>(103, 0));
vector<vector<int>> b(103, vector<int>(103, 0));
int t;

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

void nghich(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            b[i][j] = a[j][n-i+1];
        }
    }
    a = b;
}

void thuan(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            b[j][n-i+1] = a[i][j];
        }
    }
    a = b;
}

void solve(){
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> a[i][j];
        }
    }
    
    while(q--){
        cin >> t;
        if(t == 1)  thuan();
        else        nghich();
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    //a = b;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
