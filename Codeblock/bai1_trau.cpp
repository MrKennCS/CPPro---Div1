#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int a, b;   cin >> a >> b;

    ll ans = 0;
    for(int i=0; i<a; ++i){
        for(int j=0; j<b; ++j){
            ans++;
        }
    }

    cout << ans;
    //cerr << ans;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    freopen("bai1.INP", "r", stdin);
    freopen("bai1.ANS", "w", stdout);
    solve();
}
