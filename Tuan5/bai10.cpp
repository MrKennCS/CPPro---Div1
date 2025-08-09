#include<iostream>
#include<vector>

using namespace std;

int n;
int a[1000009];
long long pre[1000009];
vector<long long> mn(1000009, 1e12 + 5);
vector<bool> isPrime(1000009, true);
long long res = -1e12 - 9;

void sieve(){
    isPrime[0] = isPrime[1] = false;
     for(int i=2; i*i<=1000000; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    cin >> n;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    for(int i=1; i<=n; ++i){
        if(isPrime[i])  mn[i] = min(mn[i-1], pre[i-1]);
        else            mn[i] = mn[i-1];
    }

    for(int i=1; i<=n; ++i){
        if(isPrime[i])  res = max(res, pre[i] - mn[i]);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}