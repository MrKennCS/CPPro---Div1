#include<iostream>
#include<vector>

using namespace std;

const int lim = 1e6;
vector<bool> isPrime(lim + 6, true);
int cnt;
int res;

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=lim; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<=lim; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    for(int i=1; i<=lim; ++i)   res += (isPrime[i]);
    cout << res;
}
/*
1 -> 1e6 co 78498 snt
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}
