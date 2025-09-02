#include<iostream>
#define ll long long
using namespace std;

int n, m;
ll k;
ll l, r, mid, ans;
ll cnt;

ll kt(ll x){
    cnt = 0;
    for(int i=1; i<=n; ++i){
        cnt += min(1LL*m, x/i);
    }
    return cnt;
}

void solve(){
    cin >> n >> m >> k;

    l = 1;
    r = 1e12;

    // tim vi tri cua phan tu lon nhat <= k
    
    while(l <= r){
        mid = (l + r) >> 1;
        if(kt(mid) <= k){
            ans = mid;
            l = mid + 1;
        }else   r = mid - 1;
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}