#include<iostream>
#include<vector>

using namespace std;


const int lim = 1e6;
int n, k;
int minPrime[lim + 6];
vector<bool> isPrime(lim + 6, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=lim; ++i){
        if(minPrime[i] == 0){
            for(int j=i*i; j<=lim; j+=i){
                isPrime[j] = false;
                if(minPrime[j] == 0){
                    minPrime[j] = i;                }
            }
        }
    }
    for(int i=1; i<=lim; ++i)   if(minPrime[i] == 0)    minPrime[i] = i;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=lim; ++i)   if(isPrime[i])  cout << i << " ";
}
/*
    snt lon nhat tu 1 -> 1e6 la: 999983
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}