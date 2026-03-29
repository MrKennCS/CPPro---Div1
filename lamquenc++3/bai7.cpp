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
int a[55];
int cnt[155];
int l, r;

bool BS1 = true;

void solve(){
    cin >> n;

    l = 155;
    r = 0;

    if(n == 1){     // TH a chi co 1 phan tu
        cin >> a[0];
        cout << "YES";
        return ;
    }

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        r = max(r, a[i]);
        l = min(l, a[i]);
    }

    if(l == r){ // TH tat cac phan tu trong a deu bang nhau
        cout << "YES";
        return ;
    }

    for(int i=l; i<=r; ++i){
        if(cnt[i] == 0){
            cout << "NO";
            return ;
        }
    }
    cout << "YES\n";
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
