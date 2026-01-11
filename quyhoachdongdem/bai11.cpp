#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod  = 1e9 + 7;
int n, m;
int a[100005];
int dp[2][103];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> m;

    foru(i, 1, n)   cin >> a[i];

    if(a[1] == 0)   foru(i, 1, m)   dp[1][i] = 1;
    else                            dp[1][a[1]] = 1;

    foru(i, 2, n){
        int pre = (i - 1) & 1;
        memset(dp[i & 1], 0, sizeof(dp[i & 1]));
        if(a[i] == 0){
            foru(j, 1, m){
                if(j > 1)    add(dp[i & 1][j], dp[pre][j - 1]);
                if(j < m)    add(dp[i & 1][j], dp[pre][j + 1]);
                add(dp[i & 1][j], dp[pre][j]);
            }
        }else{
            if(a[i] > 1)    add(dp[i & 1][a[i]], dp[pre][a[i] - 1]);
            if(a[i] < m)    add(dp[i & 1][a[i]], dp[pre][a[i] + 1]);
            add(dp[i & 1][a[i]], dp[pre][a[i]]);
        }
    }

    int res = 0;
    foru(i, 1, m)   add(res, dp[n & 1][i]);

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}