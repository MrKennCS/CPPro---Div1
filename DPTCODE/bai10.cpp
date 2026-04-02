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
string s;

int val = 1;
int res;

bool SUB2 = true;

int calc(string a){
    res = 0;
    val = 1;

    for(int i=1; i<=n; ++i){
        if(a[i] == 'M') res += val;
        else            val = -val;
    }
    //cout << abs(res) << '\n';
    return abs(res);
}

void sub1(){
    res = 0;
    val = 1;

    for(int i=1; i<=n; ++i){
        if(s[i] == 'M') res += val;
        else            val = -val;
    }
    cout << abs(res) << '\n';
    return ;
}

void sub2(){
    if(k > n){
        k -= n;
        if(k & 1)   cout << n - 1 << '\n';
        else        cout << n << '\n';
    }else   cout << k << '\n';
    return ;
}

void sub3(){
    vector<int> id;
    id.pb(0);
    for(int i=1; i<=n; ++i) if(s[i] == 'D') id.pb(i);
    if(k == sz(id) - 1){
        cout << n << '\n';
        return ;
    }
    if(k > sz(id) - 1){
        k -= (sz(id) - 1);
        if(k & 1)   cout << n - 1 << '\n';
        else        cout << n << '\n';
    }else{
        string a, b;

        a = s;
        b = s;

        for(int i=1; i<=k; ++i) a[id[i]] = 'M';
        for(int i=sz(id)-k; i<sz(id); ++i)  b[id[i]] = 'M';
        //cout << a << " " << b;
        //cout << calc(a) << " " << calc(b) << '\n' << a << " " << b;
        cout << max(calc(a), calc(b)) << '\n';
    }

}

void sub4(){
    
}

void sub5(){
    
}


void solve(){
    /*
    1
    8 2
    MMDMMDDM

    */

    SUB2 = true;

    cin >> n >> k;
    cin >> s;

    s =  " " + s;

    for(int i=1; i<=n; ++i) if(s[i] == 'M') SUB2 = false;

    //sub3();
    if(k == 0)                  sub1();
    else if(SUB2)               sub2();
    else if(n <= 36 && k <= 4)  sub3();
    else if(n <= 20)            sub4();
    else                        sub5();
    /*
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    cin >> tc;
    while(tc--)  solve();

    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(start - stop);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
