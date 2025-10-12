#include<iostream>

using namespace std;

int q, n, k;
const int MOD = 1e9 + 7;

int nCk[1005][1005];

void solve(){
    n = 1000;
    for(int i=1; i<=n+1; ++i){
        for(int j=1; j<=i; ++j){
            if(i == j)  nCk[i][j] = 1;
            else{
                nCk[i][j] = (nCk[i-1][j] % MOD + nCk[i-1][j-1] % MOD) % MOD;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //cin >> q;
    solve();

    cin >> q;
    while(q--){
        cin >> n >> k;
        cout << nCk[n+1][k+1] << '\n';
    }
}