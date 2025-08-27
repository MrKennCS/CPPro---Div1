#include<iostream>

using namespace std;

int n, q, x;
int l, r, mid;
int res;
int a[1000009];
long long pref[1000009];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    cin >> q;
    while(q--){
        cin >> x;

        l = 1;
        r = n;
        /*
        5
        5 4 1 2 3
        3
        5 6 12

        5 9 10 12 15
        6

        5
        5 4 1 2 3
        1
        6

        */
        while(l <= r){
            mid = (l + r) >> 1;
            cout << l << " " << r << " " << mid << '\n';
            if(pref[mid-1] < x){
                res = mid;
                l = mid + 1;
            }else   r = mid - 1;
        }
        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(0);
    solve();
}