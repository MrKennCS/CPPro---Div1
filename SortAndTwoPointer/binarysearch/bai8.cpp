#include<iostream>
#define ll long long
using namespace std;

ll n, m, k;
ll ans;

ll cnt(ll x){
    ll res = 0;
    for(int i=1; i<=m; ++i){
        res += min(n, x / i);
    }
    return res;
}

void solve(){
    cin >> n >> m >> k;

    ll l = 1;
    ll r = 1e12;
    ll mid;

    while(l <= r){
        mid = (l + r) >> 1;
        //cout << cnt(mid) << " ";
        if(cnt(mid) >= k){
            ans = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }
    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}