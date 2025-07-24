#include<iostream>
#include<algorithm>

using namespace std;

int rev(int n){
    int ans = 0;
    while(n){
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

void solve(){
    int a, b;   cin >> a >> b;
    int res = 0;
    for(int i=a; i<=b; ++i){
        if(__gcd(i, rev(i)) == 1)   res += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(0);
    solve();
}