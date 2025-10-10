#include<iostream>
#define ll long long

using namespace std;

ll a, b;
const int MOD = 1e9 + 7;

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
    cin >> a >> b;
    cout << pow(a, b, MOD);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}