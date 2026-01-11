#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

const int mod = 1e9 + 7;
int n;
int a[103];
int lim;
int dp[100005];

void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
        lim += a[i];
    }

    dp[0] = 1;
    foru(i, 1, n){
        ford(sum, lim, a[i]){
            dp[sum] = max(dp[sum - a[i]], dp[sum]);
        }
        //foru(sum, 0, lim)   cout << dp[sum] << " ";   cout << '\n';
    }

    int res = 0;
    foru(i, 1, lim) res += (dp[i] == 1);
    cout << res << '\n';    foru(i, 1, lim) if(dp[i])   cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}