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
    Bài toán cần phân biệt các trường hợp rõ ràng khi có số 0

    TH1: Xuất hiện 0 số không

    Nếu không có số không, điều ta cần quan tâm lúc này là số lượng số âm có trong mảng

        TH1: Có lẻ số âm
        -> Ta sẽ loại phần tử có giá trị âm lớn nhất

        TH2: Có chẵn số âm
        -> Ta chỉ cần in tích tất cả các phần tử có trong mảng

    TH2: Xuất hiện 1 số không

    -> Ta buộc phải loại bỏ số không đó

    -> Ta sẽ in ra res là tích tất cả các phần tử của mảng

    TH3: Xuất hiện >1 số không
    -> Không có các nào loại ra mà tích không bằng không

    => In ra 0
*/

int n;
int a[100005];
int cnt;
int cnt0;
int mn = -1e9 - 7;
ll res = 1;

ll mul(ll a, ll b, ll m){
    ll ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt0 += (a[i] == 0);
        cnt  += (a[i] < 0);
        if(a[i] < 0)    mn = max(mn, a[i]);
    }

    if(cnt0 == 0){
        for(int i=1; i<=n; ++i) res *= abs(a[i]);
        if(cnt & 1) cout << (res / abs(mn)) % mod;
        else        cout << res % mod;
    }else if(cnt0 == 1){
        for(int i=1; i<=n; ++i) res *= a[i];
        cout << res % mod;
    }else if(cnt0 > 1)  cout << 0;


    return ;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
