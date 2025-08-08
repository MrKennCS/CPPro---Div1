#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;
int n;
int a[1000009];
long long pre[1000009];
int res = 0;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    for(int i=1; i<=n-1; ++i){
        //cout << a[i] << " " << pre[n] - pre[i] << '\n';
        res = (res % MOD + 1LL * a[i] * ((pre[n] - pre[i] + MOD) % MOD) % MOD) % MOD;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}