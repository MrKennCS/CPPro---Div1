#include<iostream>

using namespace std;

int n, m, q, x;
int L, R;
int a[100009];
int cnt[100009];
int pre[100009];
int l, r, mid, res;
// dung counting sort
void solve(){
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        cin >> L >> R;
        pre[L]++;
        pre[R+1]--;
    }

    for(int i=1; i<=n; ++i){
        pre[i] += pre[i-1];
        cnt[pre[i]]++;
    }

    int id = 1;
    for(int i=0; i<=100000; ++i){
        for(int j=0; j<cnt[i]; ++j){
            pre[id] = i;
            id += 1;
        }
    }
    // 0 1 1 2 2 3 3

    //for(int i=1; i<=n; ++i) cout << pre[i] << " ";  cout << '\n';

    cin >> q;
    while(q--){
        cin >> x;
        // tim vi tri mid sao cho pre[mid] >= x
        l = 1;
        r = n;

        while(l <= r){
            mid = (l + r) >> 1;
            if(x <= pre[mid]){
                res = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }
        if(pre[res] < x)   res = n + 1; 

        cout << n - res + 1 << '\n';
    }

}  

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}