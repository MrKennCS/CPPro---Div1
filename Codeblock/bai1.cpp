#include<bits/stdc++.h>

using namespace std;

void file(){
    if(fopen("bai1.INP", "r")){
        freopen("bai1.INP", "r", stdin);
        freopen("bai1.OUT", "w", stdout);
    }
}

int a, b;

void solve(){
    cin >> a >> b;
    cout << a << " " << b;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();
    solve();
}
