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
ll a[100005];
ll k;
ll l, r, mid, ans;

void sub1(){
    vector<ll> val;
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            val.pb(a[j] - a[i - 1]);
        }
    }
    sort(val.begin(), val.end(), greater<int>());
    cout << val[k - 1];
}

ll dem(ll x){
    ll cnt = 0;
    for(int i=1; i<=n; ++i){
        int upper = ub(a + i, a + n + 1, a[i - 1] + x) - a;
        //cout << "UPPER: " << upper << " " << n - upper + 1 << '\n';
        cnt += (n - upper + 1);
    }
    return cnt;
}

void sub2(){
    l = -1e14;
    r = 1e14;

    while(l <= r){
        mid = l + (r - l) / 2;
        if(dem(mid) < k){
            r = mid - 1;
            ans = mid;
        }else   l = mid + 1;
    }
    cout << ans;
    /*
    for(int i=1; i<=n; ++i) cout << a[i] << " ";    cout << '\n';
    for(int i=1; i<=6; ++i){
        cout << "TEST: " << i << '\n';
        cout << dem(i) << '\n';
    }
    */

}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    if(n <= 1000)   sub2();
    else            sub2();
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
