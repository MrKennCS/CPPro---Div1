#include<iostream>
#include<vector>
#include<cmath>
#define sz(a) (int)a.size()
using namespace std;

void sieve(int l, int r){
    int sqrtR = sqrt(r);

    vector<bool> mark(sqrtR + 1, false);
    vector<int> prime;

    for(int i=2; i<=sqrtR; ++i){
        if(!mark[i]){
            prime.push_back(i);
            for(int j=i*i; j<=sqrtR; j += i){
                mark[j] = true;
            }
        }
    }

    vector<bool> isPrime(r-l+1, true);
    for(int i=0; i<sz(prime); ++i){
        int start = max(prime[i]*prime[i], (l+prime[i]-1)/prime[i]*prime[i]);
        for(int j=start; j<=r; j+=prime[i]){
            isPrime[j-l] = false;
        }
    }
    if(l == 1){
        isPrime[0] = false;
    }
    int res = 0;
    for(int i=l; i<=r; ++i){
        if(isPrime[i-l])    res += 1;
    }
    cout << res << '\n';
   
}

void solve(){
    int l, r;
    cin >> l >> r;

    sieve(l, r);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    int q;  cin >> q;
    while(q--)  solve();
}