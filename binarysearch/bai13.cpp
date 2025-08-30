#include<iostream>
#define ll long long
using namespace std;

int n, k;
int a[1000009];

int check(ll x){
    ll res = 0;
    for(int i=1; i<=n; ++i) res = res + x / a[i];
    return res >= k;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    /*
    5 9
    4 6 3 9 10

    3  4  6  9 10


    */

    ll l = 0;
    ll r = 1e18;
    ll mid;
    ll res;

    while(l <= r){
        mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();   
}