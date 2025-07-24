#include<iostream>

using namespace std;

int l, r;

int tonguoc(int n){
    int res = 0;
    for(int i=1; i*i<=n; ++i){
        if(n % i == 0)  res += (n/i == i ? i : n/i + i);
    }
    return res;
}

void solve(){
    int res = 0;
    cin >> l >> r;
    for(int i=l; i<=r; ++i){
        if(tonguoc(i) > 2*i)    res += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}