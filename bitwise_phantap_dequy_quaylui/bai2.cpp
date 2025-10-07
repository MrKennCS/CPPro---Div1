#include<iostream>

using namespace std;

int n, q;
int a[100009];
int pre[100009];
int l, r;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    cin >> q;
    while(q--){
        cin >> l >> r;
        int ans = pre[r] ^ pre[l-1];
        cout << ans << '\n';
    }


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}