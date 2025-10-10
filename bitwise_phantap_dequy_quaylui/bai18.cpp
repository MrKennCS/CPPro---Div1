#include<iostream>

using namespace std;

int q;
int n, k;
unsigned long long tohop[1005][1005];
const int MOD = 1e9 + 7;

void solve(){
    cin >> n >> k;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> q;

    for(int i=1; i<=1000; ++i) tohop[i][1] = i;

    for(int i=2; i<=1000; ++i){
        for(int j=i; j<=1000; ++j){
            tohop[j][i] = (tohop[j-1][i] % MOD + tohop[j-1][i-1] % MOD) % MOD;
        }
    }
    //cout << tohop[3][1] << '\n';
    while(q--){
        cin >> n >> k;
        cout << tohop[n][k] % MOD << '\n';
    }
    //solve();
}