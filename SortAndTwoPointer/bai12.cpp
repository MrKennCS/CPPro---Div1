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

int n;
ll s;
ll a[400006];
int res = 2000006;

void sub1(){
    ll sum = 0;
    //for(int i=1; i<=2*n; ++i)   a[i] += a[i - 1];
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            sum = 0;
            for(int k=i; k<=j; ++k){
                sum += a[k];
            }
            if(sum >= s && j - i + 1 <= n / 2){
                res = min(res, j - i + 1);
            }
        }
    }
    cout << (res == 2000006 ? -1 : res);
}

void sub2(){
    for(int i=1; i<=n; ++i) a[i] += a[i - 1];

    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(a[j] - a[i - 1] >= s && j - i + 1 <= n / 2){
                res = min(res, j - i + 1);
            }
        }
    }

    cout << (res == 2000006 ? -1 : res);
}

void sub3(){    
    int l = 1;
    //cout << "GAY\n";
    for(int i=1; i<=n; ++i) a[i] += a[i - 1];

    for(int r=1; r<=n; ++r){
        if(a[r] - a[l - 1] >= s){
            if(r - l + 1 <= n / 2)  res = min(res, r - l + 1);
            while((a[r] - a[l - 1] >= s && l < r)  || r - l + 1 > n / 2)    l++;
        }
    }
    cout << (res == 2000006 ? -1 : res);
}

void solve(){
    cin >> n >> s;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i + n] = a[i];
    }
    n *= 2;

    if(n <= 100)        sub1();
    else if(n <= 2000)  sub2();
    else                sub3();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT

    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
