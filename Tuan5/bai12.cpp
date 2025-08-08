#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;
int a[1000009];

void solve(){
    cin >> m >> n >> k;
    for(int i=1; i<=m; ++i) cin >> a[i];

    sort(a + 1, a + m + 1);
    /*
    8 5 3
    1 2 3 4 5 6 7 8

    8 5 4
    1 2 3 4 5 6 7 8

    8 8 7
    1 2 4 5 6 9 11 12

    8 2
    8 -> 

    */

    //for(int i=1; i<=m; ++i) cout << a[i] << " ";    cout << '\n';
    long long res = 0;
    //cout << m-n+1 << " " << a[m-n+1] << '\n';
    for(int i=m; i>=1; i--){
        if(i-n+1 == 0)  break;
        //cout << i << " " << i-n+1 << '\n';
        if(a[i] - a[i-n+1] <= k){
            for(int j=i-n+1; j<=i; ++j) res += a[j];
            cout << res;
            return ;
        }
        /* 
        */
    }

    cout << -2;
    return ;
}


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}