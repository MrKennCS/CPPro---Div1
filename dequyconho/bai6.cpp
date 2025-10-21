#include<iostream>
#include<cstring>

using namespace std;

int n;
const int mod = 1e9 + 7;
int res;
int cal[100006];
int dp[100009];

void backtrack(int pos){
    if(pos == n + 1){
        res++;
        return ;
    }
    backtrack(pos + 1);
    if(pos + 1 <= n)backtrack(pos + 2);
}

/*
Voi moi vi tri i

dp[i] = 
*/

int dequyconho(int pos){
    if(dp[pos] != -1)   return dp[pos];

    int &ans = dp[pos];
    ans = 0;

    if(pos >= 3)    ans = dequyconho(pos-1) % mod + dequyconho(pos-2) % mod;
    else            ans = dequyconho(pos-1);

    return ans % mod;
}

void solve(){
    cin >> n;
    //backtrack(1);

    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;

    cout << dequyconho(n+1);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}