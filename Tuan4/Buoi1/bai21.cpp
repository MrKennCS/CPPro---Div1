#include<bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long l, long long r){
    return l + rd() % (r - l + 1);
}

long long mul(long long a, long long b, long long mod){
    long long ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

long long pow(long long a, long long b, long long mod){
    long long ans = 1;
    while(b){
        if(b & 1)   ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b /= 2;
        return ans;
    }
}

bool snt(long long n){
    if(n <= 2)  return (n == 2);
    for(int i=1; i<=100; ++i){
        long long x = rand(2, n-1);
        if(pow(x, n-1, n) != 1) return false;
    }
    return true;
}

void solve(){
    int n;  cin >> n;
    int a[n + 9];
    for(int i=1; i<=n+1; ++i) cin >> a[i];

    for(int i=1; i<=n+1; ++i){
        for(int j=i+1; j<=n+1; ++j){
            if(__gcd(a[i], a[j]) == 1){
                cout << a[i] << " " << a[j];
                return ;
             }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
