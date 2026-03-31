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

int n, x;
int I, J;
int trc[100005];
int sau[100005];
int a, b, c, d;
int st;

void sub1(){

}

void sub2(){

}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i){
        trc[i] = i - 1;
        sau[i] = i + 1;
    }

    sau[0] = 1;
    trc[n + 1] = n;
    /*
    for(int i=1; i<=n; ++i) if(trc[i] == 0){
        st = i;
        break;
    }

    while(st != n + 1){
        cout << st << " ";
        st = sau[st];
    }

    cout << '\n';
    */

    while(x--){
        cin >> I >> J;
        swap(I, J);

        if(trc[I] == J) continue;

        a = trc[I];
        b = sau[I];
        c = trc[J];
        d = sau[J];

        sau[c] = d;
        trc[d] = c;

        sau[a] = J;
        trc[J] = a;

        trc[I] = J;
        sau[J] = I;

    }
    
    st = 0;
    while(sau[st] != n + 1){
        cout << sau[st] << " ";
        st = sau[st];
    }

    /*
    if(x <= 1000)   sub1();
    else            sub2();
    */


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
