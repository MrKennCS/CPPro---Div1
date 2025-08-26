#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long k;
long long a[100009];
bool kt[100009];
int res;

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i=1; i<=n; ++i){
        int l = i + 1;
        int r = n;
        int mid = (l + r) >> 1;
        int fi_l = -1;
        int fi_r = -1;

        while(l <= r){
            mid = (l + r) >> 1;
            if(a[mid] >= a[i] + k){
                if(a[mid] == a[i] + k)  fi_l = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }

        l = i + 1;
        r = n;

        while(l <= r){
            mid = (l + r) >> 1;
            if(a[mid] <= a[i] + k){
                if(a[mid] == a[i] + k)  fi_r = mid;
                l = mid + 1;
            }else   r = mid - 1;
        }

        if(fi_l != -1)  res += (fi_r - fi_l + 1);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}