#include<iostream>

using namespace std;

const int LIMN = 1e5;

int uoc[LIMN + 9];

void sanguoc(){
    for(int i=1; i<=LIMN; ++i){
        for(int j=i; j<=LIMN; j+=i){
            uoc[j] += i;
        }
    }
}

void solve(){
    int l, r;   cin >> l >> r;
    int res = 0;
    for(int i=l; i<=r; ++i){
        res += (uoc[i] > 2*i);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sanguoc();
    solve();
}