#include<iostream>
#include<algorithm>

using namespace std;

int n;
int b[100009];
int c[100009];
int l, r, mid, res;
int ans = 2000000009;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) cin >> c[i];

    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    /*
    8
    -6 -3 -2 0 1 4 5 9
    -8 -3 -1 1 4 5 6 8

    6
    -4 -2 -1 3 6 9
    -9 -6 -3 1 2 4
    */
    for(int i=1; i<=n; ++i){
        // neu b[i] < 0
        l = 1;
        r = n;
        if(b[i] < 0){
            while(l <= r){
                mid = (l + r) >> 1;
                if(c[mid] <= -b[i]){
                    res = mid;
                    l = mid + 1;
                }else   r = mid - 1;
            }
            ans = min(ans, abs(b[i] + c[res]));
            if(res < n) ans = min(ans, abs(b[i] + c[res + 1]));
        }else{
            while(l <= r){
                mid = (l + r) >> 1;
                if(-c[mid] <= b[i]){
                    res = mid;
                    r = mid - 1;
                }else   l = mid + 1;
            }
            ans = min(ans, abs(b[i] + c[res]));
            if(res > 1) ans = min(ans, abs(b[i] + c[res - 1]));
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}