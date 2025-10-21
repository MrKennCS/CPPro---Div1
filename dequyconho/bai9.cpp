#include<iostream>
#include<unordered_map>

#define ull unsigned long long

using namespace std;

ull n;
unordered_map<ull, ull> dp;

ull dequy(ull pos){
    if(dp[pos] != 0)  return dp[pos];

    ull &res = dp[pos];

    res = dequy(pos/2) + dequy(pos/3);

    return res;
}

void solve(){
    cin >> n;

    dp[0] = 1;
    cout << dequy(n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}