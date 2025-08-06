#include<iostream>
#include<vector>

using namespace std;

int q, l, r;
vector<bool> isPrime(1e9 + 9, true);

void sieve(int l, int r){
    for(int i=2; i*i<=r; ++i){
        if(isPrime[i]){
            for(int j=max(i*i, (j+l-1)/i*i); j<=r; j+=i){
                isPrime[i] = false;
            }
        }
    }
    
    int sum = 0;

    for(int i=l; i<=r; ++i) sum += (isPrime[i]);
    cout << sum << '\n';
}

void truyvan(){
    cin >> l >> r;
    sieve(l, r);
}  

int main(){
    ios_base::sync_with_stdio(false);

    isPrime[0] = isPrime[1] = false;

    int q;  cin >> q;
    while(q--)  truyvan();
}