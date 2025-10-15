#include<iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int f[n + 5];
    f[0] = 1;

    for(int i=1; i<=n; ++i){
        f[i] = f[i/2] + f[i/3];
    }

    cout << f[n];
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    solve();
}