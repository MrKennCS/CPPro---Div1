#include<iostream>

using namespace std;

int n, x, q;
int u, v;
int a[100009];
long long pre[100009];
int res;

void solve(){
    cin >> u >> v;
    res += (1LL * pre[v] - pre[u-1] < x);
} 

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> n >> x >> q;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    while(q--)  solve();
    cout << res;
}