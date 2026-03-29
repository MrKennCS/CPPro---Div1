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
    1
    10 6
    1 3 2 5 4 6 8 7 9 10
*/

int n, x;
int a[200005];
int l, r;

bool DB1 = true;
vector<int> b;
ii ngoai;

void solve(){
    b.clear();
    DB1 = true;
    ngoai = {0, 1e9 + 7};

    cin >> n >> x;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i-1] > a[i])  DB1 = false;
    }

    if(DB1){
        cout << "YES\n";
        // ERROR 1
        return ;
    }

    if(n <= x){
        cout << "NO\n";
        return ;
    }

    if(n == 1){
        cout << "YES\n";
        return ;
    }

    if(2 * x <= n) cout << "YES\n";
    else{
        //cout << "GAY\n";
        l = n - x;
        r = x + 1;

        DB1 = true;
        if(l + 1 < r - 1){
            for(int i=l+2; i<=r-1; ++i) if(a[i - 1] > a[i]) DB1 = false;
        }

        if(!DB1){
            cout << "NO\n";
            return ;
        }

        for(int i=1; i<=l; ++i) b.pb(a[i]);
        for(int i=r; i<=n; ++i) b.pb(a[i]);

        sort(b.begin(), b.end());

        if(b[sz(b)/2-1] <= a[l + 1] && a[r - 1] <= b[sz(b)/2])  cout << "YES\n";
        else                                                    cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> tc;
    while(tc--)  solve();
}
