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

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
int val;
int res;

ll mul(ll a, ll b, ll mod){
    ll ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

ll pow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b & 1)   ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return ans;
}

bool snt(int x){
    if(x <= 2)   return (x == 2);
    for(int i=1; i<=100; ++i){
        ll num = rand(2, x-1);
        if(pow(num, x - 1, x) != 1)   return false;
    }
    return true;

}

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

int rev(int x){
    int ans = 0;
    while(x){
        ans = x % 10 + ans * 10;
        x /= 10;
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> val;
        res += (snt(rev(val)));
        //cout << snt(val) << " ";
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
