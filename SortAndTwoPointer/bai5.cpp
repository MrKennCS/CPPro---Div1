#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a[100009], b[100009];
int c[200009];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){    cin >> a[i];    c[i] = a[i];    }
    for(int i=1; i<=m; ++i){    cin >> b[i];    c[i+n] = b[i];  }
    //for(int i=1; i<=n+m; ++i)   cout << c[i] << " ";
    sort(c + 1, c + n+m + 1);
    for(int i=1; i<=n+m; ++i)   cout << c[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}