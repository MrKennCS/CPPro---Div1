#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long mul(long long a, long long b, long long mod){
    long long ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

long long lcm(long long a, long long b){
    return (a / __gcd(a, b)) * b;
    //return mul(a / __gcd(a, b), b, MOD);
}

bool cp(unsigned long long n){
    return ((unsigned long long)sqrt(n) == sqrt(n));
}

void solve(){
    int n;  cin >> n;
    int a[n + 9];
    for(int i=1; i<=n; ++i) cin >> a[i];
    long long bcnn = 1LL * a[1];
    for(int i=2; i<=n; ++i) bcnn = lcm(bcnn, a[i]);

    if(cp(1ULL * bcnn))    cout << bcnn % MOD;
    else{
        unsigned long long nhan = 1;
        while(!cp(1ULL * nhan * bcnn))  nhan += 1;
        cout << mul(bcnn, nhan, MOD);
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}