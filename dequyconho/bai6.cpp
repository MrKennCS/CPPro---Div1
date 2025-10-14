#include<iostream>

using namespace std;

int n;
const int mod = 1e9 + 7;
int f[100009];

void solve(){
    cin >> n;

    
    /*
    i le:

    f[i] = f[i-1] + 1;

    i chan:

    f[i] = f[i-1] * 2;

    f[1] = 1
    f[2] = 2
    f[3] = 3
    f[4] = 5
    f[5] = 8
    f[6] = 13

    */
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=n; ++i){
        f[i] = (f[i-1] % mod + f[i-2] % mod) % mod;
    }
    cout << f[n];

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}