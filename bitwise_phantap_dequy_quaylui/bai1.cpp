#include<iostream>
#include<bitset>

using namespace std;

void solve(){
    int n;  cin >> n;

    cout << bitset<32>(n) << " " << __builtin_count(n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}