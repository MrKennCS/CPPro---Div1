#include<iostream>
#define ll long long
using namespace std;

ll n;
ll l, r, mid, res;

ll cnt(ll x){
    ll ans = 0;
    ll no = 0;
    ll N = n;
    while(N){
        //cout << ans << " " << no << " " << n << '\n';
        if(N < x)   ans += N,   N = 0;
        else        ans += x,   N -= x;
        if(N >= 10) no += N/10, N -= N/10;
    }
    return ans;
}

void solve(){
    cin >> n;

    l = 1;
    r = 1e18;
    //res = 1e18 + 1;

    while(l <= r){
        mid = (l + r) >> 1;
        if(cnt(mid) >= n/2){
            res = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    solve();
}
