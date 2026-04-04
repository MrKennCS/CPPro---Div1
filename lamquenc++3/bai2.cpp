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
    6
    -2 -4 -3 -1 4 0

    4
    -2 -4 -3 4
*/

int n;
int a[100005];
int khong;
int am;
int lonnhat = -1e9 - 7;
int benhat = 1e9 + 7;
ll tich = 1;

ll mul(ll a, ll b){
    ll ans;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i] == 0)   khong++;
        else{
            benhat = min(benhat, a[i]); // co the la am co the la duong
            if(a[i] < 0){
                am++;
                lonnhat = max(lonnhat, a[i]);    // chi co the la am
            }
        }
    }

    //cout << benhat << " " << lonnhat << '\n';

    if(khong > 1){
        //cout << "TH1: khong > 1\n";
        cout << 0;
    }
    else if(khong == 1){
        //cout << "TH2: khong == 1\n";
        /*
        for(int i=1; i<=n; ++i){
            if(a[i] != 0){
                tich = (tich % mod * (1ll * a[i]) % mod) % mod;
                //cout << i << " " << a[i] << " " << tich << '\n';
            }
        }
        cout << tich % mod;
        */
        if(am & 1)  cout << 0;
        else{
            for(int i=1; i<=n; ++i){
                if(a[i] != 0){
                    tich = (tich % mod * (1ll * a[i]) % mod) % mod;
                    //cout << i << " " << a[i] << " " << tich << '\n';
                }
            }
            cout << tich % mod;
        }
        /*
        */
    }else{
        //cout << "TH3: khong == 0\n";
        if(am == 0){
            //cout << "TH3.1: mang duong\n";
            for(int i=1; i<=n; ++i) tich = (tich % mod * a[i] % mod) % mod;
        }else{
            if(am & 1){
                //cout << "TH3.2: mang co le am\n";
                int id;
                for(int i=1; i<=n; ++i) if(a[i] == lonnhat){
                    id = i;
                    break;
                }
                //cout << "ID: " << id << '\n';
                for(int i=1; i<id; ++i)     tich = (tich % mod * (1ll * a[i]) % mod) % mod;
                for(int i=id+1; i<=n; ++i)  tich = (tich % mod * (1ll * a[i]) % mod) % mod;
            }else{
                //cout << "TH3.2: mang co chan am\n";
                for(int i=1; i<=n; ++i) tich = (tich % mod * (1ll * a[i]) % mod) % mod;
            }
        }
        cout << tich % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
