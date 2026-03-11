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

*/

int k;
int a, b;
int x[10], y[10];
int ban[10][10];

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

void solve(){
    cin >> k;
    while(k--){
        cin >> a >> b;
        
        for(int i=1; i<=8; ++i)                     ban[i][b] = 1;
        for(int i=1; i<=8; ++i)                     ban[a][i] = 1;
        for(int i=a, j=b; i<=8 && j<=8; ++i, ++j)   ban[i][j] = 1;
        for(int i=a, j=b; i>=1 && j>=1; --i, --j)   ban[i][j] = 1;
        for(int i=a, j=b; i>=1 && j<=8; --i, ++j)   ban[i][j] = 1;
        for(int i=a, j=b; i<=8 && j>=1; ++i, --j)   ban[i][j] = 1;
    }

    for(int i=1; i<=8; ++i){
        for(int j=1; j<=8; ++j){
            cout << ban[i][j] << " ";
        }
        cout << '\n';
    }

    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
