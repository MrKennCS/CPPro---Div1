#include<iostream>

using namespace std;

int n;
int a[200009];
long long pre[200009];
int res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + 1LL * a[i];
    }

    for(int i=1; i<=n-1; ++i){
        res += (pre[i] - pre[0] == pre[n] - pre[i]);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}