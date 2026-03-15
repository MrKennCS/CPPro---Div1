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
3

1
5 
3 
3
5 2 2 

3
3 3 2 
2 1 4 
6
4 4 4 2 3 3 

3
3 1 3 
4 1 4 
7
3 4 1 4 5 5 1 

    Nx1: Điều kiện đầu tiên để c[i] tồn tại là tổng các chữ số thế vào phải thỏa

    // Nx2: Ở dãy d[i], phần tử d cuối cùng phải là một số đã có trong b[i]

    Sau khi thỏa có tất cả các phần tử cần thế vào, ta đi xét các trường hợp sau:

    TH1: Tồn tại phần tử có trong d[i] nhưng không có trong b[i]
->  Ta duyệt từ phải qua trái, trong lúc duyệt, ta đếm số lượng các phần tử đã đi qua rồi đến khi gặp phần tử không có trong b[i]

    TH2: Tất cả phần tử có trong d[i] đều có trong b[i]
->  Đơn giản ta chỉ cần in ra YES
*/

int n, m;
int a[200005];
int b[200005];
int d[200005];
umap<int, int> cnt;

void solve(){

    cnt.clear();

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    cin >> m;
    for(int i=1; i<=m; ++i){
        cin >> d[i];
        cnt[d[i]]++;
    }

    for(int i=1; i<=n; ++i){
        if(a[i] == b[i])    continue;

        if(cnt[b[i]] == 0){
            cout << "NO\n";
            return ;
        }

        cnt[b[i]]--;
    }

    cnt.clear();

    for(int i=1; i<=n; ++i) cnt[b[i]]++;

    if(cnt[d[m]] == 0)  cout << "NO\n";
    else                cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> tc;
    while(tc--)  solve();
}
