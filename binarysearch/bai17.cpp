#include<iostream>
#define ll long long
using namespace std;

int n, k;
ll a[1000009];
ll pre[1000009];
ll l, r, mid, res;
bool valid = false;
ll tong;
ll cnt(ll x){
    ll ans = 0;
    ll sum = 0;
    //valid = false;
    for(int i=1; i<=n; ++i){
        sum += a[i];
        if(sum > x){
            //cout << sum - a[i] << " ";
            ans += 1;
            sum = a[i];
        }
    }
    //if(sum <= x)    valid = true;
    return ans + 1;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i],    tong += a[i];
    /*
    8 3 23
    3 9 10 5 4 8 7 2

    5 3 10
    1 1 1 1 1 
    */
    
    l = 1;
    r = tong;

    while(l <= r){
        mid = (l + r) >> 1;
        //cout << l << " " << r << " " << cnt(mid) << '\n';
        if(cnt(mid) <= k){
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