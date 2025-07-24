#include<iostream>

using namespace std;

int l, r;
bool prime[100000009];
int res;
void start(){
    for(int i=2; i<=100000000; ++i)    prime[i] = true;
    prime[0] = prime[1] = false;
}

void sieve(){
    for(int i=2; i*i<=100000000; ++i){
        if(prime[i]){
            for(int j=i*i; j<=100000000; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    cin >> l >> r;
    res = 0;
    for(int i=l; i<=r; ++i) if(prime[i])    res += 1;
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    start();
    sieve();

    int q;  cin >> q;
    while(q--)  solve();
}