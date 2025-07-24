#include<iostream>

using namespace std;

bool prime[200009];

void sieve(){
    for(int i=2; i<=200000; ++i)    prime[i] = 1;
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=200000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=200000; j+=i){
                prime[j] = false;
            }
        }
    }

}

int a, b;

void solve(){
    sieve();
    cin >> a >> b;
    
    for(int i=a; i<=b; ++i)    if(prime[i])    cout << i << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}