#include<bits/stdc++.h>
#define pushb push_back
#define popb pop_back
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)


using namespace std;

const int mod = 1e9 + 7;
const int N = 105;
int n, x;
int c[N];
int dp[2000005];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i)    cin >> c[i];

    dp[0] = 1;

    foru(sum, 1, x){
        foru(i, 1, n){
            if(sum - c[i] < 0)  continue;
            if(dp[sum - c[i]] <= 0)  continue;
            add(dp[sum], dp[sum - c[i]]);
        }
    }

    cout << dp[x];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}