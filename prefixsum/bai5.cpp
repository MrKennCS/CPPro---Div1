#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

const int limN = 1e5 + 3;
int mn = -1e4 - 4;
int t, n;
int a[limN];
int sum, tong;
int res2;

void solve(){
    cin >> t;
    while(t--){
        cin >> n;
        sum = tong = 0;
        res2 = 0;
        mn = -1e4 + 4;
        foru(i, 1, n){
            cin >> a[i];
            
            if(a[i] > 0)    tong += a[i];

            sum += a[i];
            if(sum < 0) sum = 0;
            if(a[i] < 0)    mn = max(mn, a[i]);
            res2 = max(res2, sum);
        }
        cout << (tong == 0 ? mn : tong) << " " << (res2 == 0 ? mn : res2) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}