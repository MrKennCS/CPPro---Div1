#include<iostream>

using namespace std;

bool prime[3000009];

void sieve(){
    for(int i=2; i<=3000000; ++i)   prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=3000000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=3000000; j+=i){
                prime[j] = false;
            }
        }
    }
}

bool check(int n){
    int sum = 0;
    while(n){
        sum += (n % 10);
        n /= 10;
    }
    return (sum % 5 == 0);
}

int l, r;
int res;

void solve(){
    cin >> l >> r;
    for(int i=l; i<=r; ++i){
        if(prime[i])    if(check(i))    res += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}
