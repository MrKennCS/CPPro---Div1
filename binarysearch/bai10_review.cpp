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

int n, k;
int a[100005];
int b[100005];

void sub1(){
    vector<int> val;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            val.pb(a[i] + b[j]);
        }
    }
    sort(val.begin(), val.end());
    for(int i=0; i<k; ++i)  cout << val[i] << " ";
}

ll dem(ll x){
    ll cnt = 0;
    for(int i=1; i<=n; ++i){
        int upper = ub(b + 1, b + n + 1, x - a[i]) - b - 1;
        cnt += upper;
    }
    return cnt;
}

void sub2(){
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    ll l = a[1] + b[1];     // min = -2e9
    ll r = a[n] + b[n];
    ll mid, ans = 0;   // ans = 0 Do BASE để loại (do 0 là gtri không thể xuất hiện trong các tổ hợp nên để loại trừ TH ko tìm được đáp án hợp lệ)

    // O(n * log(4 * 10^9) * log(10 ^ 5))
    while(l <= r){
        mid = l + (r - l) / 2;
        if(dem(mid) >= k){
            r = mid - 1;
            ans = mid;      // ans la gia tri nho nhat thoa man dem()
        }else   l = mid + 1;
    }

    // OUTPUT
    // O((log(10 ^ 5) + n) * n)
    vector<int> val;
    for(int i=1; i<=n; ++i){
        int lower = lb(b + 1, b + n + 1, ans - a[i]) - b - 1;
        //if(lower == 0)  break;
        for(int j=1; j<=lower; ++j) val.pb(a[i] + b[j]);
    }
    sort(val.begin(), val.end());
    for(int i=0; i<sz(val); ++i)    cout << val[i] << " ";
    if(sz(val) < k){
        int tmp = k - sz(val);
        while(tmp--)    cout << ans << " ";
    }
    //cout << ans;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    if(n <= 1000)   sub1();
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
