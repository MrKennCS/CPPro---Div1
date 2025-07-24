#include<iostream>
#include<cmath>
using namespace std;

int n;
long long a[100009];
long long x;
long long dis = 1e18;
long long res;

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i] = ceil(1.0 * x / a[i]) * a[i];
    }

    for(int i=1; i<=n; ++i){
        if(a[i] - x < dis){
            dis = a[i] - x;
            res = a[i];
        }
    }

    cout << res;
    // Giai thuat
    /*
        3 5
        2 3 4

        Lay x chia a[i] lam tron len ta co

        5/2 = 3
        5/3 = 2
        5/4 = 2
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}