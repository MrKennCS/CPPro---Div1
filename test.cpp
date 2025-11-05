#include<iostream>

using namespace std;

int n;
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    if(x < mod)     x += mod;
}

void solve(){
    cin >> n;
    int res = 0;
    
    for(int i=1; i<=n; ++i){

    }
}

int main(){
    ios_base::sync_with_stdio(false);      cin.tie(0);
    solve();
}