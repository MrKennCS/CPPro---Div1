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
    8 5
    1 5 5 6 5 7 4 8

    8 5
    1 5 5 2 5 3 4 4

    8 5
    1 5 5 2 5 3 4 8
*/

int n, k;
int a[100005];
int l, r, mid, res;

int low(int l, int r, int x){
    res = 0;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(a[mid] == x){
            res = mid;
            r = mid - 1;
        }else{
            if(a[mid] < x)  r = mid - 1;
            else            l = mid + 1;
        }
    }
    return res;
}

int high(int l, int r, int x){
    res = 0;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(a[mid] == x){
            res = mid;
            l = mid + 1;
        }else{
            if(a[mid] < x)  r = mid - 1;
            else            l = mid + 1;
        }
    }
    return res;
}


void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());

    //int lower = lb(a + 1, a + n + 1, k) - a;
    //int upper = ub(a + 1, a + n + 1, k) - a;


    //for(int i=1; i<=n; ++i) cout << a[i] << " ";    cout << '\n';
    if(high(1, n, k) == low(1, n, k) && high(1, n, k) == 0) cout << 0;
    else                                                    cout << high(1, n, k) - low(1, n, k) + 1;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
