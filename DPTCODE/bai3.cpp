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

int n;
int a[100005];
int P, Q, R;
ll res;

void sub1(){
    for(int i=1; i<=n-2; ++i){
        for(int j=i+1; j<=n-1; ++j){
            for(int z=j+1; z<=n; ++z){
                if(a[i] == P && a[j] == Q && a[z] == R) res++;
            }
        }
    }
    cout << res;
}

void sub2(){
    int pre[n + 5];
    memset(pre, 0, sizeof(pre));

    for(int i=1; i<=n; ++i){
        if(a[i] == R)   pre[i]++;
        pre[i] += pre[i - 1];
    }

    //for(int i=1; i<=n; ++i) cout << pre[i] << " ";

    for(int i=1; i<=n-2; ++i){
        for(int j=i+1; j<=n-1; ++j){
            if(a[i] == P && a[j] == Q){
                res += (pre[n] - pre[j]);
            }
        }
    }

    cout << res;
}

void sub3(){
    int pre[2][n + 5];
    memset(pre, 0, sizeof(pre));

    for(int i=1; i<=n; ++i){
        if(a[i] == R)   pre[0][i]++;
        pre[0][i] += pre[0][i - 1];
    }

    for(int i=1; i<=n; ++i){
        if(a[i] == Q)   pre[1][i] += (pre[0][n] - pre[0][i]);
        pre[1][i] += pre[1][i - 1];
    }

    for(int i=1; i<=n; ++i){
        if(a[i] == P)   res += (pre[1][n] - pre[1][i]);
    }
    
    cout << res;

}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cin >> P >> Q >> R;

    if(n <= 500)        sub1();
    else if(n <= 1000)  sub2();
    else                sub3();

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
