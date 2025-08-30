#include<iostream>
#include<algorithm>

using namespace std;

int n, m, q;
int a[100009];
int pre[100009];
int l, r, mid, x;
int res;

void solve(){
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        cin >> l >> r;
        pre[l] += 1;
        pre[r + 1] -= 1;
    }
    for(int i=1; i<=n; ++i) pre[i] += pre[i-1];
    
    sort(pre + 1, pre + n + 1);
    //for(int i=1; i<=n; ++i) cout << pre[i] << " ";

    cin >> q;
    while(q--){
        cin >> x;

        l = 1;
        r = n;

        res = 0;

        while(l <= r){
            mid = (l + r) >> 1;
            if(pre[mid] < x){
                res = mid;
                l = mid + 1;
            }else   r = mid - 1;
        }

        cout << n - res << '\n';

    }
    /*
    7 4
    1 3
    2 5
    1 2
    5 6
    4
    1
    7
    4
    2

    0  0  0  0  0  0  0
    1    -1
    1  1 -1       -1
    1    -1
                1    -1

->  2  3  2  1  2  1  0

    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}