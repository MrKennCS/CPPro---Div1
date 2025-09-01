#include<iostream>
#define ll long long
using namespace std;

int n;
ll m;
int a[100009];
ll pre[100009];
int lv, mx;
int l, r, mid, res;

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    lv = a[1];

    for(int i=2; i<=n; ++i){
        if(a[i] >= lv){
            lv = a[i];
        }else{
            pre[a[i]+1]++;
            pre[lv+1]--;
        }
    }

    for(int i=1; i<=mx; ++i) pre[i] += pre[i-1];
    for(int i=1; i<=mx; ++i) pre[i] += pre[i-1];
    for(int i=1; i<=mx; ++i)    cout << pre[i] << " ";  cout << '\n';

    l = 0;
    r = mx;
    ll x = pre[mx] - m;
 
    while(l <= r){
        mid = (l + r) >> 1;
        if(pre[mid] <= x){
            res = mid;
            l = mid + 1;
        }else   r = mid - 1;
    }
    cout << pre[res] << " " << x << '\n';
    if(pre[res] > x)    res = -1;
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
