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
#define turnon(x, y) ((x) |= (1LL << y))
#define turnof(x, y) ((x) &= ~(1LL << y))
#define daobit(x, y) ((x) ^= (1LL << y))
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^ (ll)(new char));

ll randInt(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
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

int n, m;
int Pow[10];
int cnt[1000006];
ll res;

ll palin(int nua, int l){
    ll p = nua; // Sửa thành long long
    int temp = (l & 1 ? (nua / 10) : nua);
    
    for(int i=0; i<l/2; ++i){
        p = p * 10 + temp % 10;
        temp /= 10;
    }
    return p;
}

void solve(){
    cin >> n >> m;

    Pow[0] = 1;
    // Khởi tạo đến Pow[9] là đủ cho việc sinh 'h' (vì h <= 5)
    for(int i=1; i<=9; ++i) Pow[i] = Pow[i - 1] * 10;

    int l = n / 2;
    int h = (l + 1) / 2;

    // Tính 10^l % m để dịch nửa đầu
    ll pow10_l = 1;
    for(int i = 1; i <= l; ++i){
        pow10_l = (pow10_l * 10) % m;
    }

    // Nửa đầu (P1)
    for(int i = Pow[h - 1]; i <= Pow[h] - 1; ++i){
        ll xau = palin(i, l); // Sửa '1' thành 'l' và dùng 'll'
        cnt[(xau % m * pow10_l) % m]++; // Sửa hệ số nhân thành pow10_l
    }

    // Nửa sau (P2)
    for(int i = 0; i <= Pow[h] - 1; ++i){ // Sửa điều kiện vòng lặp (<= thay vì <)
        ll xau = palin(i, l); // Dùng 'll'
        res += cnt[(m - xau % m + m) % m];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    //cin >> tc;
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
