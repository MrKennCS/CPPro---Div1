#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
int a[100009];
int b[100009];
int l, r, res;
long long mid;
vector<int> final;

int cnp(int x){
    // tim vi tri mid lon nhat ma b[mid] <= x - a[i];
    l = 1;
    r = n;

    while(l <= r){
        mid = (l + r) >> 1;
        if(b[mid] <= x){
            l = mid + 1;
            res = mid;
        }else   r = mid - 1;
    }
    if(b[res] > x)    res = 0;
    //cout << res << " ";
    return res;
}

int cnt(int x){
    long long ans = 0;
    for(int i=1; i<=n; ++i){
        int tmp = cnp(x - a[i]);
        if(tmp == 0)    return ans;
        ans += tmp;
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    /*
    3 3
    1 7 11
    2 4 6
    */
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    l = -2e9;
    r = 2e9;

    while(l <= r){
        mid = (1LL*l + r) >> 1;
        cout << mid << " ";
        if(cnt(mid) >= k){
            r = mid - 1;
        }else   l = mid + 1;
    }
    cout << l << " " << r << '\n'; 
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();

}