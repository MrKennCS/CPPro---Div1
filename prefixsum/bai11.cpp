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
#define turnon(x, y) ((x) | (1LL << y))
#define turnof(x, y) ((x) ^ (1LL << y))
#define foru(i, a, b)   for(int i=a; i<=b; ++i)
#define ford(i, a, b)   for(int i=a; i>=b; --i)
#define foruc(i, a, b, c)   for(int i=a; i<=b; i+=c)
#define fordc(i, a, b, c)   for(int i=a; i>=b; i-=c)
#define y1 trungkientuyentinhoc
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

int n, q;
int a[505][505];
int den[505][505];
int trang[505][505];
int x1, x2, y1, y2;

int calc(int x1, int y1, int x2, int y2){
    int t = trang[x2][y2] - trang[x1 - 1][y2] - trang[x2][y1 - 1] + trang[x1 - 1][y1 - 1];
    int d = den[x2][y2] - den[x1 - 1][y2] - den[x2][y1 - 1] + den[x1 - 1][y1 - 1];
    return abs(t - d);
}

void solve(){
    cin >> x1 >> y1 >> x2 >> y2;

    cout << calc(x1, y1, x2, y2) << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT

    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> a[i][j];
            den[i][j] = den[i - 1][j] + den[i][j - 1] - den[i - 1][j - 1];
            trang[i][j] = trang[i - 1][j] + trang[i][j - 1] - trang[i - 1][j - 1];
            if((i + j) & 1) den[i][j] += a[i][j];
            else            trang[i][j] += a[i][j];
        }
    }
    /*
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << den[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "---\n";
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << trang[i][j] << " ";
        }
        cout << '\n';
    }
    */
    cin >> tc;
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
