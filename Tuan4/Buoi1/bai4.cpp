#include<bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long l, long long r){
    return l + rd() % (r - l + 1);
}

long long mul(long long a, long long b, long long mod){
    long long res = 0;
    while(b){
        if(b & 1)   res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}

long long pow(long long a, long long b, long long mod){
    long long res = 1;
    while(b){
        if(b & 1)   res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

bool snt(long long a){
    if(a <= 2)  return (a == 2);
    for(int i=1; i<=100; ++i){
        long long x = rand(2, a-1);
        if(pow(x, a-1, a) != 1) return false;
    }
    return true;
}

long long n;

void solve(){
    cin >> n;
    while(n){
        if(!snt(n)){
            cout << "KHONG";
            return ;
        }
        n /= 10;
    }
    cout << "PHAI";
    /*
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}