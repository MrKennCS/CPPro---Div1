#include<iostream>
#include<vector>

using namespace std;

int n;
int a[1000009];
long long pre[1000009];
vector<bool> isPrime(1000009, true);

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
        //cout << pre[i] << " ";
    }
    cout << '\n';
    long long res = -1000009;
    for(int i=2; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(isPrime[i] && isPrime[j]){
                //out << i << " " << j << " " << pre[j] - pre[i-1] << '\n';
                res = max(res, pre[j] - pre[i-1]);
            }
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}
