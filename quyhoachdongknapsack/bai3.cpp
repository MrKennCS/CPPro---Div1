#include<iostream>
#include<cstring>

using namespace std;

int n, s;
int val;
int w[103];
int v[103];
long long dp[100005];;

void solve(){
    cin >> n >> s;
    for(int i=1; i<=n; ++i){
        cin >> w[i] >> v[i];
        val += v[i];
    }

    /*
    Goi dp[i] la so can nhe nhat de co the lay duoc so mon do co tong gia tri v bang i
    
    BASE:

    Truong hop lay so do vat co tong gia tri bang 0
->  dp[0] = 0;
->  dp[v[i]] = min(dp[v[i]], w[i]);
    */
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    
    for(int i=1; i<=n; ++i){
        for(int j=val; j>=v[i]; --j){
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }

    for(int i=val; i>=1; --i){
        if(dp[i] <= s){
            cout << i;
            return ;
        }
        /*
        */
        //cout << i << " " << dp[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}