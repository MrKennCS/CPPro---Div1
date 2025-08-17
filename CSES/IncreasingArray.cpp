#include<iostream>

using namespace std;

int n;
int a[200009];
long long res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        if(a[i] >= a[i-1])  continue;
        else{
            res += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}