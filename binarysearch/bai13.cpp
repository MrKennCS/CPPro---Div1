#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n, k;
int a[1000009];
ll l, r, mid, res;

ll cnt(ll x){
    ll ans = 0;
    for(int i=1; i<=n; ++i){
        ans += x / a[i];
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    l = 0;
    r = 1e18;

    while(l <= r){
        mid = (l + r) >> 1;
        //cout << cnt(mid) << " ";
        if(cnt(mid) >= k){
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