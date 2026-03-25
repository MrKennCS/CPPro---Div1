// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define int long long
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
7
1 2
1 3 
1 4
1 5
1 4
1 6
1 7

*/

struct phanso{
    int id = 0;
    int tu = 0;
    int mau = 0;
};

int n;
phanso arr[1003];
phanso res1, res2;

phanso cong(phanso a, phanso b){
    phanso ans;
    ans.tu = a.tu * b.mau + b.tu * a.mau;
    ans.mau = a.mau * b.mau;
    return ans;
}

phanso tru(phanso a, phanso b){
    phanso ans;
    ans.tu = abs(a.tu * b.mau - b.tu * a.mau);
    ans.mau = a.mau * b.mau;
    return ans;
}

phanso toigian(phanso a){
    phanso ans;
    ans.tu = a.tu / __gcd(a.tu, a.mau);
    ans.mau = a.mau / __gcd(a.tu, a.mau);
    ans.id = a.id;
    return ans;
}

int ss(phanso a, phanso b){
    // a >  b -> true;
    // a <= b -> false;
    if(a.tu * b.mau > a.mau * b.tu && a.mau * b.mau > 0)    return 1;
    else if(a.tu * b.mau == a.mau * b.tu)                   return 2;
    else                                                    return 3;
}

bool cmp(phanso a, phanso b){
    if(ss(a, b) == 3)   return true;
    if(ss(a, b) == 2)   return (a.id < b.id);
    return false;
}

void test(){
    phanso ps1, ps2;

    cin >> ps1.tu >> ps1.mau;
    cin >> ps2.tu >> ps2.mau;

    cout << ss(ps1, ps2) << " " << ss(ps2, ps1);
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i].tu >> arr[i].mau;
        arr[i].id = i;
    }

    res1.tu = res1.mau = res1.id = 0;
    res2.tu = res2.mau = res2.id=  0;

    for(int i=1; i<=n-1; ++i){
        phanso cong_tam = cong(arr[i], arr[i + 1]);
        phanso tru_tam = tru(arr[i], arr[i + 1]);

        //cong_tam = toigian(cong_tam);
        //tru_tam = toigian(tru_tam);
        //phanso tru_tam = a[i].tru(a[i], a[i + 1]);

        // khu truong hop dau tien cua res1
        if(res1.tu == 0 && res1.mau == 0){
            res1.tu = cong_tam.tu;
            res1.mau = cong_tam.mau;
        }else if(ss(cong_tam, res1) == 1){
            res1.tu = cong_tam.tu;
            res1.mau = cong_tam.mau;
        }

        if(res2.tu == 0 && res2.mau == 0){
            res2.tu = tru_tam.tu;
            res2.mau = tru_tam.mau;
        }else if(ss(tru_tam, res2) == 1){
            res2.tu = tru_tam.tu;
            res2.mau = tru_tam.mau;
        }

        //cout << cong_tam.tu << " " << cong_tam.mau << '\n';
        //cout << tru_tam.tu << " " << tru_tam.mau << '\n';
    }

    sort(arr + 1, arr + 1 + n, cmp);
    //cout << " ========== \n\n";

    res1 = toigian(res1);
    res2 = toigian(res2);

    cout << res1.tu << " " << res1.mau << '\n';
    cout << res2.tu << " " << res2.mau << '\n';
    for(int i=1; i<=n; ++i) cout << arr[i].id << " ";
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--){
        solve();
        //test();
    }
}
