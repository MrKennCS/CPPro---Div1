#include<iostream>
#include<cmath>

using namespace std;

int n, m;
int cnt_cp;
int cnt_not_cp;
long long res;

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
    }
    return ans;
}

bool cp(int x){
    return ((int)sqrt(x) == sqrt(x));
}

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; ++i) if(cp(i))   cnt_cp += 1;
    cnt_not_cp = n - cnt_cp;

    res += 1LL * pow(2, cnt_not_cp + 1, m) + 1LL * m;
    res %= m;
    cnt_cp -= 1;

    while(cnt_cp){
        res += 1LL * pow(2, cnt_not_cp, m) 1LL * m;
        res %= m;
        cnt_cp -= 1;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}