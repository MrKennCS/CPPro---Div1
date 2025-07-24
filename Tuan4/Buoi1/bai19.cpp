#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long mul(long long a, long long b, int mod = MOD){
    long long ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

long long lcm(long long a, long long b){
    return mul(a, b) / __gcd(a, b);
}

bool cp(long long num){
    return ((long long)sqrt(num) == sqrt(num));
}

int n;
int a[100009];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    long long bcnn = a[1];
    for(int i=2; i<=n; ++i){
        bcnn = lcm(bcnn, 1LL*a[i]) % MOD;
    }
    
    if(cp(bcnn))    cout << bcnn;
    else{
        int nhan = 1;
        while(!cp(mul(nhan, bcnn)))   nhan++;
        cout << mul(bcnn, nhan);
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
