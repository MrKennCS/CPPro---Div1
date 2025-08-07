#include<bits/stdc++.h>

using namespace std;

int l, r, k;

void solve(){
    cin >> l >> r >> k;

    if(l > r){
        cout << 0;
        return ;
    }

    int i=l;
    while(i<=r && i%k!=0)   i += 1;
    if(i > r){
        cout << 0;
        return ;
    }

    int j=r;
    while(j>=l && j%k!=0)   j -= 1;
    if(j < l){
        cout << 0;
        return ;
    }

    if(i == j){
        cout << i;
        return ;
    }

    int n = j/k - i/k + 1;
    cout << 1LL*n*(i + j)/2;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}