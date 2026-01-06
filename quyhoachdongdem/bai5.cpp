#include<bits/stdc++.h>
#define str string
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define sz(a) (int)a.size()

using namespace std;

const int mod = 1e9 + 7;
const int lim = 1003;
int H, W;
int a[lim][lim];
int dp[lim][lim];

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void solve(){
    cin >> H >> W;

    foru(i, 1, H){
        str tmp;    cin >> tmp;
        foru(j, 0, W-1) if(tmp[j] == '#')   a[i][j + 1] = -1;
    }

    dp[1][1] = 1;
    foru(i, 1, H){
        foru(j, 1, W){
            if(a[i][j] != -1){
                add(dp[i + 1][j], dp[i][j]);
                add(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    /*
    foru(i, 1, H){
        foru(j, 1, W){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    cout << dp[H][W];
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}