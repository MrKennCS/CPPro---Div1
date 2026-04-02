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
int a[100005];

int uoc[1000006];

void INPUT(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
}

int cnt_uoc(int n){
    int ans = 0;
    for(int i=1; 1ll*i*i<=n; ++i){
        if(n % i == 0){
            if(n / i != i)  ans += 2;
            else            ans += 1;
        }
    }
    return ans;
}

void trau(){
    // O(n can n) ~ 1e8
    for(int i=1; i<=n; ++i){
        cout << cnt_uoc(a[i]) << '\n';
    }
}

void sanguoc(){                     // O()
    for(int i=1; i<=1000000; ++i){
        for(int j=i; j<=1000000; j+=i){
            uoc[j] += 1;
        }
    }
}

void solve(){
    sanguoc();
    for(int i=1; i<=n; ++i) cout << uoc[a[i]] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();
    INPUT();
    // Bat dau do
    /*
    */
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    
    while(tc--){
        solve();
        //trau();
    }

    // Dung do
    /*
    */
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
