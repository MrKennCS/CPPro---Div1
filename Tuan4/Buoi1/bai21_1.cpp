#include<iostream>
#include<algorithm>

using namespace std;

void solve(){
    int n;  cin >> n;
    int a[n + 9];
    for(int i=1; i<=n+1; ++i) cin >> a[i];
    sort(a + 1, a + n + 2);
    for(int i=1; i<=n; ++i){
        if(a[i] == a[i+1]-1){
            cout << a[i] << " " << a[i+1];
            return ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}