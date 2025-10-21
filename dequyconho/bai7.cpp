#include<iostream>
#include<cstring>

#define ll long long

using namespace std;

int n;
int a[1000009];
ll dp[1000009];
ll res;

int dequy(int pos){
    if(pos == 0)    return 0;
    if(pos == 1)    return dp[1];
    if(pos == 2)    return dp[2];
    if(dp[pos] != -1)   return dp[pos];
    

    //int &res = dp[pos];
    ll th1 = dequy(pos-1);
    ll th2 = dequy(pos-2);
    ll th3 = dequy(pos-3);

    ll &res = dp[pos];

    res = max(th1, th2 + a[pos]);
    res = max(res, th3 + a[pos] + a[pos-1]);

    return dp[pos];
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];


    cout << dequy(n);
    /*
    
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}