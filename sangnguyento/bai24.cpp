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

const int mod = 998244353;
int tc = 1;

/*

*/

int n;
int res;
int uoc[100007];

void sanguoc(){
    for(int i=1; i<=100000; ++i)  uoc[i] = 1;
    //memset(uoc, 1, sizeof(uoc));
    for(int i=1; i<=100000; ++i){
        for(int j=i; j<=100000; j+=i){
            uoc[j] = (1ll * uoc[j] * i) % mod;
        }
    }
}

void sub1(){
    cout << uoc[n] << '\n';
}

void sub2(){
    cout << uoc[n] << '\n';
}

void sub3(){
    
}

void chuan(){

}

void solve(){
    cin >> n;
    

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT
    // END_INPUT
    
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    cin >> tc;
    sanguoc();
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
