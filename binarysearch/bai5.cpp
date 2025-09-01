#include<iostream>
#define int long long

using namespace std;

int n, q, x;
int a[1000009];
long long pre[1000009];
int l, r, mid, res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    cin >> q;
    while(q--){
        cin >> x;

        l = 1;
        r = n;
        // tim mid BE NHAT ma pre[mid] <= x
        while(l <= r){
            mid = (l + r) >> 1;
            if(pre[mid] >= x){
                res = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }

        cout << res << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}