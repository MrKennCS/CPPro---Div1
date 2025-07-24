#include<iostream>

using namespace std;

int a, b;

void solve(){
    cin >> a >> b;

    for(int i=1; i<=min(a, b); ++i){
        if(a % i == 0 && b % i == 0){
            cout << i << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}