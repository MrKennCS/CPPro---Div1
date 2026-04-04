//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int q;
int l, r;
int pre[10000007];
int spf[10000007];
int uoc[10000005];

bool factor(int n){
    int cur = 0;
    int cnt = 0;
    int soluong = 0;
    while(n > 1){
        cur = 0;
        int p = spf[n];
        while(n % p == 0){
            cur++;
            n /= p;
        }
        cnt += cur;
        soluong++;
        if(soluong >= 3)    return false;
    }
    if(soluong == 1 && cnt == 3)    return true;
    if(soluong == 2 && cnt == 2)    return true;
    return false;
}

void sanguoc(){
    for(int i=1; i<=10000000; ++i){
        for(int j=i; j<=10000000; j+=i){
            uoc[j] += 1;
        }
    }
}

void sangspf(){
    for(int i=1; i<=10000000; ++i)  spf[i] = i;
    spf[0] = spf[1] = 1;
    for(int i=2; 1ll*i*i<=10000000; ++i){
        if(spf[i] == i){
            for(int j=i*i; j<=10000000; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void sub1(){
    sanguoc();
    for(int i=1; i<=100000; ++i)    pre[i] = pre[i - 1] + (uoc[i] == 4);
    while(q--){
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
}

void sub2(){
    sanguoc();
    for(int i=1; i<=10000000; ++i)  pre[i] = pre[i - 1] + (uoc[i] == 4);
    while(q--){
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
}

void sub3(){
    for(int i=1; i<=10000000; ++i)  pre[i] = pre[i - 1] + factor(i);
    while(q--){
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }

}

void solve(){
    cin >> q;

    if(q <= 10)         sub1();
    else if(q <= 100)   sub2();
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
