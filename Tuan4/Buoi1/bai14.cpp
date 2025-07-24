#include<iostream>

using namespace std;

long long gcd(long long a, long long b){
    while(b){
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void solve(){
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}