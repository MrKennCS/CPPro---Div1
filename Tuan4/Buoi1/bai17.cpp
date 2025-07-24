#include<iostream>

using namespace std;

int rev(int n){
    int n_ = 0;
    while(n){
        n_ = n_*10 + n%10;
        n /= 10;
    }
    return n_;
}

int gcd(int a, int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int l, r;
int res;

void solve(){
    cin >> l >> r;
    for(int i=l; i<=r; ++i){
        int daonguoc = rev(i);
        if(gcd(i, daonguoc) == 1){
            if(daonguoc > r)    cout << i << '\n';
            else                cout << i << " " << daonguoc << '\n';
            res += (daonguoc <= r ? 2 : 1);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}