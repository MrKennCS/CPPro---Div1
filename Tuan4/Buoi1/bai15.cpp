#include<iostream>

using namespace std;

int l, r, k;

void solve(){
    cin >> l >> r >> k;
    
    while(l % k != 0)   l++;
    if(l > r){
        cout << 0;
        return ;
    }
    long long res = 0;
    while(l <= r){
        res += 1LL*l;
        l += k;
    }
    cout << res;    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}