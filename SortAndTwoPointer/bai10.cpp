#include<iostream>
#include<algorithm>

using namespace std;

int n, x;
int a[200009];
int res;

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    int l=1;
    int r=n;

    while(l <= r){
        if(a[l] + a[r] > x){
            r -= 1;
            res += 1;
        }else{
            l += 1;
            r -= 1;
            res += 1;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}