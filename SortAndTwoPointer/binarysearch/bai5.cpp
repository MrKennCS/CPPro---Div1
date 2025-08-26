#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int a[1000009];
long long pre[1000009];
int x;
int res;
int mid;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    cin >> q;
    while(q--){
        cin >> x;
        /*
        5
        5 4 1 2 3
        3
        5 6 12
        
        5 4 1 2 3
        1 2 3 4 5 6

        ???
        */
        int l = 1;
        int r = n;

        while(l <= r){
            mid = (l + r) >> 1;
            if(x > pre[mid]){
                res = mid;
                l = mid + 1;
            }else   r = mid - 1;
        }

        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}