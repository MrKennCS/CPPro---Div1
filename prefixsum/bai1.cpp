#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std; 

const int limN = 1e5 + 3;
int n, x, q;
int a[limN];
ll pre[limN];
int l, r;
int res;

ll get(int L, int R){
    if(L > R)   return 0;
    return pre[R] - pre[L - 1];
}

void solve(){
    cin >> n >> x >> q;
    foru(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    while(q--){
        cin >> l >> r;
        res += (get(l, r) <= x);
    }

    cout << res;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}