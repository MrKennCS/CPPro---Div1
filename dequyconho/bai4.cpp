#include<iostream>

using namespace std;

int k, n;
int hu[100009];
int res[100009];
const int mod = 14062008;

void solve(){
    cin >> n >> k;

    res[1] = 1;
    res[2] = 1;

    for(int i=1; i<=k; ++i){
        cin >> hu[i];
        res[hu[i]] = -1;
    }
    /*
    =  =  =  =  =

    f[1] = 1
    f[2] = 1
    f[3] = 2
    f[4] = 3
    f[5] = 5
    */
    for(int i=3; i<=n; ++i){
        if(res[i] != -1){
            int cong1 = (res[i-1] == -1 ? 0 : res[i-1]);
            int cong2 = (res[i-2] == -1 ? 0 : res[i-2]);
            //cout << cong1 << " " << cong2 << '\n';
            res[i] = cong1 + cong2;
            res[i] %= mod;
        }
    }
    cout << res[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}