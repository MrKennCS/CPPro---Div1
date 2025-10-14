#include<iostream>
#define ull unsigned long long
#define ll long long
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n;
ull a[200009];
ull res;

void solve(){
    cin >> n;
    
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        int cnt = __builtin_ctzll(a[i]);
        res = max(res, (1ULL << cnt));
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}