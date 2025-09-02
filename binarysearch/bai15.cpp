#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int n, m;
int a[1000009];
int l, r, mid, res;

ll cnt(int x){
    ll ans = 0;
    for(int i=1; i<=m; ++i){
        ans += ceil(1.0 * a[i] / x);
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> a[i];

    l = 1;
    r = 1e9;

    while(l <= r){
        mid = (l + r) >> 1;
        if(cnt(mid) <= n){
            r = mid - 1;
            res = mid;
        }else   l = mid + 1;
    }

    cout << res;
}  

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}