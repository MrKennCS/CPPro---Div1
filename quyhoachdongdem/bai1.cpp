#include<iostream>

using namespace std;

int n;
long long m;
long long dp[55];

void solve(){
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << min(dp[n], m);
}
/*
Trang thai:

Goi dp[i] la so nha tham hiem buoc duoc den o thu i
-> res = dp[n+1]

Voi moi buoc, nha tham hiem co the buoc duoc 1, 2, 3 o
-> Voi moi i, xet 3 truong hop dp[i-1]. dp[i-2], dp[i-3] de cap nhat cho dp[i]

Vong for:
for i voi i tu 3 -> n
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}