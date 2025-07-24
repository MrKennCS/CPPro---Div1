#include<bits/stdc++.h>
using namespace std;

bool prime[10000009];

void sieve(){
    for(int i=2; i<=10000000; ++i)   prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=10000000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=10000000; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int a, b;   cin >> a >> b;
    if(a < 0)   a = 0;
    if(b < 0){
        cout << 0 << '\n';
        return ;
    }
    long long sum = 0;
    int cnt = 0;
    for(int i=a; i<=b; ++i){
        if(prime[i]){
            sum += 1LL*i;
            cnt += 1;
        }
    }
    //cout << sum << " " << cnt << '\n';
    cout << fixed << setprecision(2) << 1.0 * sum / cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    int q;  cin >> q;
    while(q--)  solve();
}