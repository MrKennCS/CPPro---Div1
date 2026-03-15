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
const int LIMN = 1e5 + 5;
int tc = 1;

/*
        1. Tìm dãy con (không cần liên tiếp) khác rỗng có tổng lớn nhất
    
    * -1e4 <= a[i] <= 1e4

    Note: Gọi res1 là đáp án cần tìm (res1 = -1e9 - 5)

    TH1: Nếu mảng có số dương hoặc 0 (a[i] >= 0)
    res1 = sum(mọi a[i] thuộc a) (ĐK: a[i] >= 0);

    TH2: Nếu mảng không có số dương hoặc 0
    res1 = số ấm lớn nhất

        2. Tìm đoạn con liên tiếp khác rỗng lớn nhất
    Bài toán quen thuộc -> Ta sẽ duy trì một biến sum là tổng, với mỗi a[i], ta xét:

    sum += a[i];

    if(sum < 0){
        res2 = max(res2, sum - a[i]);
        sum = 0;
    }

    cout << res2

2
4
1 2 3 4
6
2-1 2 3 4-5
*/

int n;
int a[LIMN];

// cs1
bool coduong = false;
int mn_am = -1e9 - 5;

int res1;
int res2;
int sum;

void solve(){
    cin >> n;

    coduong = false;
    res1 = 0;
    res2 = 0;
    sum = 0;
    mn_am = -1e9 - 5;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i] >= 0)   coduong = true;
        else            mn_am = max(mn_am, a[i]);         
    }

    // Cs1
    //cout << (coduong ? 1 : 0) << '\n';

    if(coduong){
        for(int i=1; i<=n; ++i) if(a[i] >= 0)   res1 += a[i];
    }else{
        res1 = mn_am;
    }
    //cout << res1 << '\n';

    //Cs2

    if(coduong){
        for(int i=1; i<=n; ++i){
            sum += a[i];
            if(sum < 0){
                res2 = max(res2, sum - a[i]);
                sum = 0;
            }else   res2 = max(res2, sum);
        }
    }else   res2 = mn_am;

    cout << res1 << " " << res2 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> tc;
    while(tc--)  solve();
}
