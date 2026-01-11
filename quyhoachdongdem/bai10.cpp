#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)

using namespace std;

const int N = 1e4 + 3;
int n, k;
int dp[N];

int get(int l, int r){
    if(l > r)   return 0;
    if(l == 0)  return dp[r];
    return (dp[r] - dp[l - 1]);
}

void solve(){
    cin >> n >> k;

    dp[0] = 1;

    for(int i=1; i<=n + 1; ++i){
        if(i <= k)  dp[i] = dp[i - 1];
        else        dp[i] = get(i - k, i - 1);
        dp[i] += dp[i - 1];
    }


    //cout << (1LL << n) << '\n';
    cout << (1LL<<n) - dp[n ];
}

void sinh(){
    cin >> n >> k;
    for(int mask=0; mask<(1LL<<n); ++mask){
        for(int i=0; i<n; ++i){
            cout << getbit(mask, i);
        }
        cout << '\n';
    }
}
/*
0000
1000
0100
0010
1010
0001
1001
0101



1100

0110
1110

1101
0011
1011
0111
1111
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
    //sinh();
}