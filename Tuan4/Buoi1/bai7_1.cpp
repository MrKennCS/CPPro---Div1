#include<bits/stdc++.h>

using namespace std;

vector<bool> prime(200009, true);

void sieve(){
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=200000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=200000; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int l, r;   cin >> l >> r;
    for(int i=l; i<=r; ++i){
        if(prime[i])  cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}