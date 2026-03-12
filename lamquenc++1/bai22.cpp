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

struct Time{
    int h, m;
    ll s;

    Time add(Time a, Time b){
        Time ans;
        ans.h = a.h + b.h;
        ans.m = a.m + b.m;
        ans.s = a.s + b.s;

        ans.m += ans.s / 60;
        ans.s %= 60;

        ans.h += ans.m / 60;
        ans.m %= 60;

        return ans;
    }

    Time diff(Time a, Time b){
        Time ans;

        ll giaya = 1ll * a.h * 60 * 60 + a.m * 60 + a.s;
        ll giayb = 1ll * b.h * 60 * 60 + b.m * 60 + b.s;
        
        ans.s = abs(giaya - giayb);
        //cout << "GIAY: " << ans.s << '\n';

        //cout << ans.s << '\n';
        ans.m = ans.s / 60;
        ans.s %= 60;

        ans.h = ans.m / 60;
        ans.m %= 60;

        return ans;
    }
};

Time A, B;

void solve(){
    cin >> A.h >> A.m >> A.s;
    cin >> B.h >> B.m >> B.s;

    Time r1 = A.add(A, B);
    Time r2 = A.diff(A, B);

    cout << r1.h << " " << r1.m << " " << r1.s << '\n';
    cout << r2.h << " " << r2.m << " " << r2.s;
}   

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
