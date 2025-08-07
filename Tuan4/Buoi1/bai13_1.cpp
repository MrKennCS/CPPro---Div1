#include<bits/stdc++.h>

using namespace std;

const int lim = 1e6;

int n;
int minPrime[lim + 9];
int a[lim + 9];
int mx, res;

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
}

int factor(int x){
    if(x == 1)  return 0;
    int res = 0;
    while(x != 1){
        res += 1;
        //cout << minPrime[x] << " ";
        x /= minPrime[x];
    }
    if(x > 1)   res += 1;
    return res;
}

void solve(){
    cin >> n;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        int tmp = factor(a[i]);
        mx = max(mx, tmp);
        res += tmp;
    }
    cout << res - mx;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}