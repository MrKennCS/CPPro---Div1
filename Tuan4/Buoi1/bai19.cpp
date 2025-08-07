#include<iostream>
#include<cmath>
#include<vector>
#define int long long
using namespace std;

const int lim = 1e7;
const int MOD = 1e9 + 7;
int mu[lim + 9];
int a[lim + 9];
int res = 1;

vector<int> minPrime(lim + 9, 0);

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

void factor(int x){
    if(x == 1)  return ;

    int mu_tmp = 0;
    int cur_minPrime = minPrime[x];

    while(x > 1){
        if(minPrime[x] == cur_minPrime) mu_tmp += 1;
        else{
            mu[cur_minPrime] = max(mu[cur_minPrime], mu_tmp);
            cur_minPrime = minPrime[x];
            mu_tmp = 1;
        }
        x /= minPrime[x];
    }
    
    if(x > 1)   mu[x] = max(mu[x], 1*1LL);
    else        mu[cur_minPrime] = max(mu[cur_minPrime], mu_tmp);
    
    //for(int i=1; i<=lim; ++i)   if(mu[i] != 0)  cout << i << " " << mu[i] << '\n';   
}

int mul(int a, int b, int mod){
    int ans = 0;
    while(b){
        if(b & 1)   ans = (ans + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}

int pow(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b & 1)   ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return ans;
}

void solve(){
    int n;  cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        factor(a[i]);
    }

    for(int i=1; i<=lim; ++i){
        if(mu[i] & 1){
            mu[i] += 1;
            res = 1LL * res * pow(i, mu[i], MOD);
            res %= MOD;
            //cout << pow(i, mu[i], MOD) << " ";
        }
        else if(mu[i] != 0){
            res = 1LL * res * pow(i, mu[i], MOD);
            res %= MOD;
            //cout << pow(i, mu[i], MOD) << " ";
        }

    }

    cout << res % MOD;
    /*
    */
    
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}