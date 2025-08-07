#include<bits/stdc++.h>

using namespace std;

long long n, m;

long long gcd(long long a, long long b){
    while(b){
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void solve(){
    cin >> n >> m;
    cout << gcd(n, m);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}