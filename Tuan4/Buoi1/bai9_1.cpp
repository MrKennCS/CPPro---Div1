#include<bits/stdc++.h>

using namespace std;

int minPrime[1000009];
vector<bool> isPrime(1000009, true);
void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=1000000; ++i){
        if(minPrime[i] == 0){
            for(int j=i*i; j<=1000000; j+=i){
                isPrime[j] = false;
                if(minPrime[j] == 0){
                    minPrime[j] = i;
                }
            }
        }
    }
    for(int i=0; i<=1000000; ++i)   if(minPrime[i] == 0)    minPrime[i] = i;
}

void solve(){
    int n;  cin >> n;
    
    if(n < 6){
        cout << 0;
        return ;
    }

    int res = 0;



    for(int i=1; i*i<=n; ++i){
        if(n % i == 0){
            if(minPrime[i] * minPrime[i] == i / minPrime[i])    res += 1;
            else if(isPrime[i / minPrime[i]])                   res += 1;
            if(n/i != i){
                int n_i = n/i;
                if(minPrime[n_i] * minPrime[n_i] == n_i / minPrime[n_i])    res += 1;
                else if(isPrime[n_i / minPrime[n_i]])                       res += 1;
            }
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    sieve();
    solve();
}