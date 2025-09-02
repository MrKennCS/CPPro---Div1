#include<iostream>
#define ll long long
using namespace std;

int n, k, t;
ll l, r, mid, res;

ll cnt(ll x){
    return x - x/n - (x % n != 0 ? 1 : 0);
}

void solve(){
    cin >> n >> k;

    l = 0;
    r = 1e18;

    while(l <= r){
        mid = (l + r) >> 1;
        if(cnt(mid) < k){
            res = mid;
            l = mid + 1;
        }else   r = mid - 1;
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> t;
    while(t--)  solve();
}
/*
3   
2 9 5
3 5 3
4 5 6
*/