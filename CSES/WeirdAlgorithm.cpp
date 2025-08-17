#include<iostream>

using namespace std;

unsigned long long n;

void solve(){
    cin >> n;

    while(n != 1){
        cout << n << " ";
        if(n & 1)   n = n * 3 + 1;
        else        n /= 2;
    }
    cout << 1;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}