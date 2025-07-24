#include<iostream>
#include<cmath>

using namespace std;

int n, m;

int cnt;
long long ans;

long long mul(long long a, long long b, long long mod){
    long long res = 0;
    while(b){
        if(b & 1)   res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}

long long pow(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b & 1)   res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

bool cp(int n){
    return ((int)sqrt(n) == sqrt(n));
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) if(cp(i))   cnt += 1;
    
    int c = n - cnt;    // c la so luong so khong phai so chinh phuong
    ans += pow(2, c + 1, m) + 1LL * m;
    cnt -= 1;
    
    if(cnt == 0){
        cout << ans % m;
        return ;
    }

    while(cnt--){
        ans += (pow(2, c, m) + 1LL * m);
        ans %= m;
    }

    cout << ans % m;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
