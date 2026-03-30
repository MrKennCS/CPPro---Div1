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

const int LIMN = 5e5 + 5;
const int mod = 1e9 + 7;
int tc = 1;

/*
    Cần quản lý những gì?

    share[i]: là số share mà người i đã mua
    tien[i]: là số tiền hiện tại của người i
    cur là số share mà công ty profit từ


    3 10
    1 1 5
    2 3
    1 2 10
    2 2
    3 1
    2 4
    1 1 5
    2 10
    3 2
    3 1

    Nx1:
    O truy van loai 2, thay vi ta di cong lan luot nhu vay, ta dat nhat tu chung va khi nay ta co so tien cua p la:

    m[p] = s[p] * (v1 + v2 + ... + vn);

    Nx2:
    Khi gap truy van 3, ta se tien hanh reset m[p] = 0, DONG THOI NEU GOI CUR[i] LA SO CO PHIEU CONG TY NGUOI I CO
    -> Ta se reset CUR[i] = 0

=>  Khi nay moi lan goi truy van 3, ta chi can in ra:

    m[p] = s[p] * cur[p]
    cur[p] = 0;

    Vay lam sao de duy tri mang cur[p]?

    1. Ngay tho:
        Voi moi truy van 2, ta cong lan luot cur[i: 1 -> n] += v
        -> DPT ko khac gi trau
    
    2. Toi uu
        Ta goi V la tong so co phan cua cong ty tu dau toi gio

        V = cur_1[i] + cur_2[i] + ... + cur_n[i] voi cur_i[i] la tong so co phieu nguoi i co sau i lan RESET
    =>  Goi TONG[i] la so co phieu da bi reset cua nguoi i

    =>  cur_i = V - tong[i]

*/

int n, q;
int loai;
int p, x, v;
int s[LIMN];
int tong[LIMN];

// trau
ll m[LIMN];

// solve
ll cur;

void add(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void trau(){
    cin >> n >> q;

    while(q--){
        cin >> loai;
        if(loai == 1){
            cin >> p >> x;

            s[p] += x;
        }else if(loai == 2){
            cin >> v;

            cout << "---------- UPDATE ----------\n";
            for(int i=1; i<=n; ++i){
                cout << "m[" << i << "] = " << m[i] << " + " << s[i] << " * " << v << " = ";
                m[i] += 1ll * s[i] * v;
                cout << m[i] << '\n';
            }
        }else{
            cin >> p;

            cout << "---------- RESET ----------\n";
            cout << "NGUOI THU " << p << "DA BI RESET TIEN VE 0\n\n";

            cout << m[p] << '\n';
            m[p] = 0;
        }
    }
}

void solve(){
    cin >> n >> q;

    while(q--){
        cin >> loai;
        if(loai == 1){
            cin >> p >> x;
            s[p] += x;
        }else if(loai == 2){

        }else{

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--){
        //trau();
        solve();
    }
}