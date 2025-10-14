#include<iostream>
#define ll long long
using namespace std;

ll x, y, n, m;

ll mul(ll a, ll b, ll mod){
    ll res = 0;
    while(b){
        if(b & 1)   res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;  
    }
    return res;
}

ll pow(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b & 1)   res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

void solve(){
    cin >> x >> y >> n >> m;
    ll tmp1 = pow(x, n, m);
    ll tmp2 = pow(y, n, m);
    cout << (tmp1 - tmp2 + m) % m;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}