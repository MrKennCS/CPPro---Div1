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
int a[1000005];
vector<bool> prime(1000005, 1);
vector<int> id;
ll pre[1000006];

ll pow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1)   ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void sangsnt(){
    prime[0] = prime[1] = 0;
    for(int i=2; 1ll*i*i<=1000000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
        }
    }
}

bool snt(int n){
    if(n <= 2)  return (n == 2);
    for(int i=1; i<=100; ++i){
        int x = rand(2, n - 1);
        if(pow(x, n - 1, n) != 1)   return false;
    }
    return true;
}

void sub1(){
    ll sum = 0;
    ll res = -1e9 + 7;

    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(!snt(i)) continue;
            if(!snt(j)) continue;
            //cerr << "CASE(l, r): " << i << " " << j << '\n';
            sum = 0;
            for(int k=i; k<=j; ++k){
                sum += a[k];
            }
            res = max(res, sum);
        }
    }
    cout << res;
}

void sub2(){
    // Di duyet all doan [l, r]
    ll res = -3e9 + 7;

    for(int i=1; i<=n; ++i) pre[i] = pre[i - 1] + a[i];
    
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(!prime[i])   continue;
            if(!prime[j])   continue;
            res = max(res, pre[j] - pre[i - 1]);
        }
    }
    cout << res;
}

void sub3(){
    for(int i=2; i<=n; ++i) if(prime[i])    id.pb(i);
    for(int i=1; i<=n; ++i) pre[i] = pre[i - 1] + a[i];
    ll res = -1e12 - 7;
    ll mn = 1e12 - 7;

    for(int i=0; i<sz(id); ++i){
        mn = min(mn, pre[id[i] - 1]);
        res = max(res, pre[id[i]] - mn);
    }
    cout << res;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    if(n <= 100){
        //sub1();

        sub1();
    }else if(n <= 3000){                 // O(n ^ 2 + n*log(log(n)) + n)
        sangsnt();
        sub2();
    }else{
        sangsnt();
        sub3();
    }
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
