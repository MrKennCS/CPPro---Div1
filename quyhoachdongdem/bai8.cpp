#include<bits/stdc++.h>
#define sz(a) (int)a.size()
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int m, n;
string tmp, s;
int q;
int dp[202][202];

void add(int &x, int y){
    x += y;
    if(x >= m)    x -= m;
}

void solve(){
    cin >> m;
    while(cin >> tmp){
        //cin >> tmp;
        n = sz(tmp);
        s = " " + tmp;

        memset(dp, 0, sizeof(dp));

        foru(i, 1, n)   dp[i][i] = 1;
        ford(i, n - 1, 1){
            foru(j, i + 1, n){
                dp[i][j] = (1LL * dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + m) % m;
                if(s[i] == s[j])    add(dp[i][j], dp[i + 1][j - 1] + 1);
            }
        }
        
        /*
        foru(i, 1, n){
            foru(j, 1, n){
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
        */

        cout << (dp[1][n] + 1) % m << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}