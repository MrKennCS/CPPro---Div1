#include<iostream>

using namespace std;

int q;
int nCk[1005][1005];
const int MOD = 1e9 + 7;

void solve(){
    cin >> q;

    for(int i=0; i<=1000; ++i){
        for(int j=0; j<=i; ++j){
            if(i == j)  nCk[i][j] = 1;
            else        nCk[i][j] = (nCk[i-1][j] % MOD + nCk[i-1][j-1] % MOD) % MOD;
        }
    }

    while(q--){
        int n, k;   cin >> n >> k;
        cout << nCk[n][k] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();


}