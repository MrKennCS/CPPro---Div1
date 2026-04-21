// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

#define sz(a) (int)a.size()
#define getbit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x) |= (1LL << y))
#define turnof(x, y) ((x) &= ~(1LL << y))
#define daobit(x, y) ((x) ^= (1LL << y))
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^ random_device{}());

ll randInt(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
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

bool col[10];
bool chinh[20];
bool phu[20];
int a[10][10];
ll res;

void gen(int row){
    if(row == 9){
        res++;
        return ;
    }

    for(int i=1; i<=8; ++i){
        if(a[row][i] == 0)  continue;

        if(!col[i] && !chinh[row - i + 8] && !phu[row + i]){
            col[i] = true;
            chinh[row - i + 8] = true;
            phu[row + i] = true;

            gen(row + 1);

            col[i] = false;
            chinh[row - i + 8] = false;
            phu[row + i] = false;
        }
    }
}

void solve(){
    for(int i=1; i<=8; ++i){
        for(int j=1; j<=8; ++j){
            char val;   cin >> val;
            a[i][j] = (val == '.');
        }
    }

    gen(1);

    cout << res;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    //cin >> tc;
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}

// RATE ?? (?/10)