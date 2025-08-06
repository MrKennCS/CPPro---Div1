#include<iostream>
#include<vector>

using namespace std;

vector<bool> isPrime(3000009, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=3000000; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<=3000000; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

bool valid(int n){
    if(!isPrime[n]) return false;
    int sum = 0;
    while(n){
        sum += (n % 10);
        n /= 10;
    }
    return (sum % 5 == 0);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    
    int l, r;   cin >> l >> r;

    sieve();
    int res = 0;
    for(int i=l; i<=r; ++i) res += valid(i);
    cout << res;
}