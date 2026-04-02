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

const int LIMN = 3000000;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int l, r;
bool snt[LIMN + 5];
int res;

void INPUT(){
    cin >> l >> r;
}

void sangsnt(){ // O(nlog(log(n))) ~ 1e7
    snt[0] = snt[1] = 1;
    for(int i=2; 1ll*i*i<=LIMN; ++i){
        if(snt[i] == 0){
            for(int j=i*i; j<=LIMN; j+=i){
                snt[j] = 1;
            }
        }
    }
}

int sumnum(int n){ // Do 1 <= l <= r <= 3e6    -> O(6) ~ O(1)
    int ans = 0;
    while(n){
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

void solve(){
    sangsnt();
    for(int i=l; i<=r; ++i){
        if(snt[i] == 0){
            if(sumnum(i) % 5 == 0)  res++;
        }
    }

    cout << res;
    //cout << snt[l] << " " << snt[r] << '\n';
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

    while(tc--)  solve();

    // Dung do
    /*
    */
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
