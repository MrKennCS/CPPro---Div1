#include<iostream>
#define ll long long
using namespace std;

ll n, q, x;
ll l, r, mid;
ll res;
ll a[1000009];
ll pref[1000009];

void solve(){
    cin >> n;
    for(ll i=1; i<=n; ++i){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    /*
    5
    6 4 7 3 2
    22
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
    6 10 17 20 22
    */
    
    cin >> q;
    while(q--){
        cin >> x;

        l = 1;
        r = n;

        // tim vi tri be nhat >= 
        while(l <= r){
            mid = (l + r) >> 1;
            if(pref[mid] >= x){
                res = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }
        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(0);
    solve();
}