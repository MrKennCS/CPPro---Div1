#include<bits/stdc++.h>

using namespace std;

int a, b;
long long sum;
int cnt;
vector<bool> isPrime(10000009, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=10000000; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<=10000000; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    cin >> a >> b;

    sum = 0;
    cnt = 0;

    for(int i=a; i<=b; ++i){
        if(isPrime[i]){
            //cout << i << " ";
            sum += i;
            cnt += 1;
        }
    }

    cout << fixed << setprecision(2) << 1.0 * sum / cnt << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    int q;  cin >> q;
    while(q--)  solve();
}