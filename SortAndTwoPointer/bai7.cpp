#include<iostream>

using namespace std;

int n, m;
int a[100009];
int b[100009];
int c[100009];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) cin >> b[i];

    int i = 1;
    for(int j=1; j<=m; ++j){
        while(a[i] < b[j] && i <= n)  i += 1;
        c[i] = i-1;
        cout << c[i] << " ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}