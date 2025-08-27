#include<iostream>
#define ll long long

using namespace std;

ll n, k;
ll res;

bool kt(ll x){
    return (x - x/n >= k);
}

void solve(){
    cin >> n >> k;

    ll l = 1;
    ll r = 1e18;
    ll mid;

    while(l <= r){
        mid = (r + l) >> 1;
        if(kt(mid)){
            res = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    int q;  cin >> q;
    while(q--)  solve();
}