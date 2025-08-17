#include<iostream>

using namespace std;

int n, x;
int a[1000009];
int sum;

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i) cin >> a[i];
    int i=1;
    int j=n;

    while(a[i] + a[j] != x){
        if(i >= j){
            cout << "No solution";
            return ;
        }
        if(a[i] + a[j] > x) j -= 1;
        else                i += 1;
    }
    cout << i << " " << j;
}
/*
6 100
2 3 5 7 9 12

*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}