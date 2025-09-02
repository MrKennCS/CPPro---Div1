#include<iostream>
#include<queue>

using namespace std;

int n, l, d;
int a[100009];
int mn = 1e9;
int ans;
priority_queue<int> qu;
void solve(){
    cin >> n >> l >> d;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    int l=1;
    int r=l;

    for(int i=l; i<=r; ++i) qu.push(a[i]),  mn = min(mn, a[i]);

    while(r <= n){

        while(qu.top() - mn <= d){
            r++;
            qu.push(a[r]);
            mn = min(mn, a[r]);
            ans += 1;
        }
        cout << l << " " << r << " " << ans << '\n';

    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}