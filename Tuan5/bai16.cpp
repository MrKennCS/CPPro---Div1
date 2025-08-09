#include<iostream>

using namespace std;

const int lim = 1e7;
int q;
int l, r;
int minPrime[lim + 9];
int pre[lim + 9];

bool check(int x){
    if(minPrime[x] == x)    return false;
    if(1LL * minPrime[x] * minPrime[x] == x / minPrime[x])  return true;
    if(minPrime[x / minPrime[x]] == x / minPrime[x] && x / minPrime[x] != minPrime[x])  return true;
    return false;
}

void sieve(){
    for(int i=2; i*i<=lim; ++i){
        if(minPrime[i] == 0){
            for(int j=i*i; j<=lim; j+=i){
                if(minPrime[j] == 0){
                    minPrime[j] = i;
                }
            }
        }
    }
    for(int i=1; i<=lim; ++i)   if(minPrime[i] == 0)    minPrime[i] = i;
    
    for(int i=1; i<=lim; ++i)   pre[i] = pre[i-1] + (check(i));
}


void solve(){
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }
}
/*
6 8 10 14 15 21 22 26 27 33 34 35 38 39 46 51 55 57 58 62 65 69 74 77 82 85 86 87 91 93 94 95
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}