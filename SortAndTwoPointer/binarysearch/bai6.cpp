#include<iostream>
#include<algorithm>

using namespace std;

int n;
int c[100009];
int b[100009];
int res = 2000000009;

int lower(int l, int r, int x){
    // vi tri be nhat >= x
    int mid = (l + r) >> 1;
    while(l <= r){
        mid = (l + r) >> 1;
        if(x <= c[mid]){
            r = mid - 1;
        }else   l = mid + 1;
    }
    if(c[mid] < x)  return mid + 1;
    return mid;
}

int upper(int l, int r, int x){
    // vi tri lon nhat <= x 
    int mid = (l + r) >> 1;
    while(l <= r){
        mid = (l + r) >> 1;
        if(c[mid] <= x){
            l = mid + 1;
        }else   r = mid - 1;
    }
    if(c[mid] > x)  return mid - 1;
    return mid;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) cin >> c[i];

    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);

    /*
    6
    -5 -2  0  1  5  9
    -4  4  1  5  7  8

    2
    -4 -2
    -2 -1
    */

    for(int i=1; i<=n; ++i){    // duyet b[i] voi i tu 1 -> n
        
        if(b[i] >= 0){
            // neu b[i] >= 0    -> tim c[i] be nhat sao cho c[i] >= -b[i]
            //cout << "Lower: " << c[lower(1, n, -b[i])] << '\n';
            res = min(res, abs(b[i] + c[lower(1, n, -b[i])]));
        }else{  
            // neu b[i] < 0 -> time c[i] lon nhat sao cho c[i] <= -b[i]
            //cout << "Upper: " << c[upper(1, n, -b[i])] << '\n';
            res = min(res, abs(b[i] + c[upper(1, n, -b[i])]));
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}