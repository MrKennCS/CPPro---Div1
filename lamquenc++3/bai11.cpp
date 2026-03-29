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

int n, k;
int a[200005];

bool check1 = true;
bool check2 = true;

void sub2(){
    int last[k + 5];
    memset(last, 0, sizeof(last));
    for(int i=1; i<=n; ++i){
        if(last[a[i] % k] <= a[i]){
            last[a[i] % k] = a[i];
        }else{
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
    return ;
}

ii cmp(ii a, ii b){
    if(a.fi == b.fi)    return a;
    if(a.fi < b.fi)     return a;
    return b;
}

void sub3(){
    vector<ii> val;
    val.pb({-1, -1});

    for(int i=1; i<=n; ++i) val.pb({a[i] % k, i});

    sort(val.begin(), val.end());
    //for(int i=1; i<sz(val); ++i)    cout << val[i].fi << " " << val[i].se << '\n';

    for(int i=1; i<sz(val); ++i){
        if(val[i - 1].fi != val[i].fi)  continue;
        else{
            if(a[val[i - 1].se] > a[val[i].se]){
                cout << "No\n";
                return ;
            }
        }
    }

    cout << "Yes\n";
}

void solve(){

    check1 = true;

    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(i > 1 && a[i - 1] > a[i])    check1 = false;
        if(a[i] > k)                    check2 = false;
    }

    if(check1 || check2){
        cout << "Yes\n";
        return ;
    }

    if(k == 1)          cout << "No\n";
    else if(k <= 2e5)   sub2();
    else                sub3();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> tc;
    while(tc--)  solve();
}
