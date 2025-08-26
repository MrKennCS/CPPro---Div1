#include<iostream>
#include<algorithm>

using namespace std;

int n, x;
int a[1000009];

int lower(int l, int r){
    // vi tri be nhat >= x
    int mid = (l + r) >> 1;
    while(l <= r){
        mid = (l + r) >> 1;
        if(x <= a[mid]){
            r = mid - 1;
        }else   l = mid + 1;
    }
    if(a[mid] < x)  return mid + 1;
    return mid;
}

int upper(int l, int r){
    // vi tri lon nhat <= x 
    int mid = (l + r) >> 1;
    while(l <= r){
        mid = (l + r) >> 1;
        if(a[mid] <= x){
            l = mid + 1;
        }else   r = mid - 1;
    }
    if(a[mid] > x)  return mid - 1;
    return mid;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i];
    
    cout << "lower: " << lower(1, n) << '\n';
    cout << "upper: " << upper(1, n) << '\n';

}
/*
    10 5
    1 2 3 4 6 7 8 9 10 11
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    solve();
}
