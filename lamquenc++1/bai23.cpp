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

struct PhanSo{
    int id = 0;
    ll tu = 0;
    ll mau = 0;
};

int n;
PhanSo ps[1005];
PhanSo res1, res2;

PhanSo toigian(PhanSo a){
    PhanSo ans;

    if(a.mau < 0){
        a.tu = -a.tu;
        a.mau = -a.mau;
    }

    ans.tu = a.tu / __gcd(abs(a.tu), abs(a.mau));
    ans.mau = a.mau / __gcd(abs(a.tu), abs(a.mau));
    ans.id = a.id;
    return ans;
}

PhanSo cong(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = a.tu * b.mau + a.mau * b.tu;
    ans.mau = a.mau * b.mau;
    return toigian(ans);
}

PhanSo tru(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = abs(a.tu * b.mau - a.mau * b.tu);
    ans.mau = abs(a.mau * b.mau);
    return toigian(ans);
}

int ss(PhanSo a, PhanSo b){
    a = toigian(a);
    b = toigian(b);

    // TH1: a == b
    if(a.tu == b.tu && a.mau == b.mau)  return 1;

    // TH1: a > b -> 1LL * (a.tu * b.mau - a.mau * b.tu) * (a.mau * b.mau) > 0
    if(((a.tu * b.mau - a.mau * b.tu) > 0 && (a.mau * b.mau) > 0) || 
       ((a.tu * b.mau - a.mau * b.tu) < 0 && (a.mau * b.mau) < 0))  return 2;
    else                                                            return 3;
}

bool cmp(PhanSo a, PhanSo b){
    if(ss(a, b) == 1)   return (a.id < b.id);
    if(ss(a, b) == 3)   return true;
    else                return false;
}

void test(){
    PhanSo a, b;
    cin >> a.tu >> a.mau >> b.tu >> b.mau;

    PhanSo res1 = cong(a, b);
    PhanSo res2 = tru(a, b);

    cout << res1.tu << " " << res1.mau << '\n';
    cout << res2.tu << " " << res2.mau << '\n';

    cout << ss(a, b);   
    
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> ps[i].tu >> ps[i].mau;
        ps[i].id = i;
    }

    res1 = cong(ps[1], ps[2]);
    res2 = tru(ps[1], ps[2]);

    for(int i=2; i<=n-1; ++i){
        PhanSo cur1 = cong(ps[i], ps[i + 1]);
        PhanSo cur2 = tru(ps[i], ps[i + 1]);

        if(ss(cur1, res1) == 2) res1 = cur1;
        if(ss(cur2, res2) == 2) res2 = cur2;
    }

    res1 = toigian(res1);
    res2 = toigian(res2);

    sort(ps + 1, ps + 1 + n, cmp);

    cout << res1.tu << " " << res1.mau << '\n';
    cout << res2.tu << " " << res2.mau << '\n';
    for(int i=1; i<=n; ++i){
        cout << ps[i].id << " ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--){
        solve();
        //test();
    }
}
