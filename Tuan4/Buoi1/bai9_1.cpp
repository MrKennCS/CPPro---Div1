#include<bits/stdc++.h>

using namespace std;

int minPrime[1000009];

void sieve(){
    for(int i=2; i*i<=1000000; ++i){
        if(minPrime[i] == 0){
            for(int j=i*i; j<=1000000; j+=i){
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

    for(int i=6; i<=n; ++i){
        if(minPrime[i] * minPrime[i] == i / minPrime[i] || minPrime[i / minPrime[i]] == i / minPrime[i])    res += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    sieve();
    solve();
}