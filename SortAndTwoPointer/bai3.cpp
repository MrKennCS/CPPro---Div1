#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100009];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}