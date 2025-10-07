#include<iostream>

using namespace std;

int n, q;
int a[100009];
int sum;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            sum += (a[i] ^ a[j]);
        }
    }
    cout << sum << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}