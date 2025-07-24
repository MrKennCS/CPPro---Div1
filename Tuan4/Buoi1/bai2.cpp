#include<iostream>

using namespace std;

int n;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        if(n % i == 0)  cout << i << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    solve();
}