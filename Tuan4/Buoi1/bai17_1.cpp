#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int check(int n){
    int N = 0;
    int tmp = n;
    while(n){
        N = N*10 + n % 10;
        n /= 10;
    }
    return (gcd(tmp, N) == 1);
}

void solve(){
    int a, b;   cin >> a >> b;

    int res = 0;
    for(int i=a; i<=b; ++i){
        res += check(i);
    }
    cout << res;
    /*
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}