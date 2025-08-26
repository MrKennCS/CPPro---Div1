#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;
int a[200009];
int b[200009];
int res;

void solve(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int pos = 1;

    for(int i=1; i<=n; ++i){
        while(pos <= m && b[pos] < a[i] - k)    pos += 1;
        if(pos <= m && a[i] + k >= b[pos]){
            res += 1;
            pos += 1;
        }
    }
    cout << res;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}